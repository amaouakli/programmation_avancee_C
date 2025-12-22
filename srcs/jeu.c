#include "jeu.h"


int ** createGrille () {     // allocation dynamique d'une matrice 4 * 4 
    int ** g = (int ** ) malloc (  TAILLE* sizeof(int *)) ; 
    if (!g )  {
        perror("Erreur d'allocation mémoire");
        exit(-1); 

    }
    for ( int  i = 0 ; i < TAILLE ; i ++ ){
        g[i] = ( int * )malloc (TAILLE * sizeof ( int ));
        if ( !g[i] ){
            for ( int j = 0 ; j < i ; j++){
                free(g[i]);
            }
            free(g);
            perror("Erreur d'allocation mémoire");
        }

    }

    return g ;
} 



void liberGrille (int ** g ){  // liberation de la grille
    for( int i  = 0 ; i < TAILLE ; i ++ ) {
        free(g[i]);
    }
   free(g);
}


void initGrille ( int ** g ){   // initialisation de la grille avec des 0 
    for ( int i = 0 ; i < TAILLE ; i ++ ){ // on parcour toutes les colonnes et lignes
        for ( int j = 0 ; j < TAILLE ; j++){
            g[i][j] = 0 ; // initialisation à 0 
        }

    }
}


int caseVide ( int **g , int i , int j) {   // renvoie  1  si la case est vide sinon 0
    if ( g[i][j] == 0 ) { 
        return 1 ;
    }  
    return 0 ;
}


int nbCaseVide ( int **g ){    // compte le nombre de cases vides 
    int cpt  = 0 ;
    for ( int i = 0 ; i  < TAILLE ; i ++  ){
        for( int j = 0 ; j < TAILLE ; j ++){
            if (caseVide (g , i, j ) ){ // appel pour  verifier si la caseVide 
                cpt ++ ;
            }
        }
    }
    return cpt ;
}


int ajouterTuile (int ** g ){             // ajouter une tuile selon rand 
    int nombreCaseVide = nbCaseVide (g );
    if (nombreCaseVide == 0 ){   // si le nombre de case vide est 0 on peut plus poser des tuilles 
        return 0;
    }
    int cpt = 0 ;
    int choix = rand() % nombreCaseVide ; // On tire au hasard un index parmi les cases vides disponibles

    for( int i = 0 ; i < TAILLE ; i ++ ){ // parcourir toutes la matrice 
        for( int j = 0 ; j < TAILLE ; j++){
            if( caseVide (g , i , j)){ 
                if ( cpt == choix){ // si le compteur atteint l'index choisi aleatoirement
                    if (rand() % 100 < AVOIRQ) { // si on choisi une valeur entre 0- 99< 10  qui arrive rarement
                        g[i][j] = 4; // on pose 4 
                    } else {
                        g[i][j] = 2; // sinon on met un 2 cas le plus fréquent
                    }
                    return 1 ;
                }
                cpt ++ ;
            }
        }
    }
    return 0 ;
}



void initJeu(int **g, int *score) {   // initialiser le plateau et deux cases 2/4
    initGrille(g);
    ajouterTuile(g);
    ajouterTuile(g);
    *score = 0;    // score à 0 
}


int calcul(int ligne[TAILLE] , int *score) {   // le calule d'un resultat d'un movement 
    int mov = 0;
    for (int j = 0 ; j < TAILLE - 1 ; j++) {     
        for (int i = 0 ; i < TAILLE - 1 ; i++) {
            if ( ligne[i] == 0 && ligne[i+1] != 0) { // on echange les elements si l'un est 0 et le suivant est ! nul
                ligne[i] = ligne[i+1] ;
                ligne[i+1] = 0;
                mov = 1;
            }
        }
    }
    for (int i = 0 ; i < TAILLE - 1 ; i++) {    // on multiplie les elements adjacents s'ils sont egaux
        if ( ligne[i] != 0 && ligne[i] == ligne[i+1]) {
            ligne[i] = ligne[i] * 2;
            *score = *score + ligne[i];
            ligne[i+1] = 0;
            mov= 1 ;
        }
    }
    
    for (int j = 0 ; j < TAILLE - 1 ; j++) {    // on echange pour mettre les nombre non nuls à gauche et les 0 à droite
        for (int i = 0 ; i < TAILLE - 1 ; i++) {
            if (ligne[i] == 0 && ligne[i+1] != 0) {

                ligne[i] = ligne[i+1] ;
                ligne[i+1] = 0;
                mov= 1 ;
            }
        }
    }
    
    return mov;
}


 
int movGauche(int **g , int *score) {    
    int mov= 0;
    int temp[TAILLE];   // tableau temporaire pour traiter une ligne à la fois
    
    for (int i = 0 ; i < TAILLE ; i++) {
        for (int j = 0 ; j < TAILLE ; j++) {  // extraire uneligne à la fois 
            temp[j] = g[i][j];
        }
        
        if (calcul(temp , score)) { // calcul de resultat sur cette ligne 
            mov= 1;
            
            for (int j = 0 ; j < TAILLE ; j++) { // recopier le resultat 
                g[i][j] = temp[j];
            }
        }
    }
    return mov;
}





int movDroite(int **g, int *score) {  
    int mov = 0;
    int temp[TAILLE]; //tableau temporaire pour traiter une ligne à la fois
    
    for (int i = 0; i < TAILLE; i++) {    // on parcourt chaque ligne de la grille
        for (int j = 0; j < TAILLE; j++) {
            temp[j] = g[i][TAILLE - 1 - j];  // On remplit le temp en partant de la fin de la ligne
        }
        
        if (calcul(temp, score)) { // appliquer le changement 
            mov = 1;
            for (int j = 0; j < TAILLE; j++) { // recopier
                g[i][TAILLE - 1 - j] = temp[j];
            }
        }
    }
    return mov;
}


int enHaut(int **g, int *score) {   // en haut 
    int mov = 0;
    int temp[TAILLE];  
    for (int j = 0 ; j < TAILLE ; j++) {  // parcours par colonne 
        for (int i = 0 ; i < TAILLE ; i++) {
            temp[i] = g[i][j];
        }
        if (calcul(temp, score)) {
            mov = 1;
            for (int i = 0 ; i < TAILLE ; i++) { // recopier le resultat dans la ligne concernée 
                g[i][j] = temp[i];
            }
        }
    }
    return mov;
}


int enBas(int **g , int *score) { // en bas c'est la meme idee que à doite c'est la ligne inversée
    int mov = 0;
    int temp[TAILLE];
    
    for (int j = 0 ; j < TAILLE ; j++) {
        for (int i = 0 ; i < TAILLE ; i++) {
            temp[i] = g[TAILLE - 1 - i ][j];
        }

        if (calcul(temp , score)) {
            mov = 1;
            for (int i = 0 ; i < TAILLE ; i++) {
                g[TAILLE - 1 - i][j] = temp[i];
            }
        }
    }
    return mov;
}


int deplacer(int **g) {                 // tester si on peut deplacer encore ou pas 
    for (int i = 0 ; i < TAILLE ; i++) {
        for (int j = 0 ; j < TAILLE - 1 ; j++) { // On parcourt chaque ligne pour chercher deux tuiles identiques côte à côte
            if (g[i][j] == g[i][j + 1]) {
                return 1;  // si un calcul horizontal est possible
            }
        }
    }
    for (int j = 0 ; j < TAILLE ; j++) {
        for (int i = 0 ; i < TAILLE - 1 ; i++) {  // On parcourt chaque colonne pour chercher deux tuiles identiques l'une sur l'autre
            if (g[i][j] == g[i + 1][j]) { // si un calcul verticale est possible
                return 1;
            }
        }
    }
    
    return 0; 
}


int estTermine(int **g) {       // si le nombre de case vide > 0 on peut encore continuer 
    if (nbCaseVide (g) > 0) {
        return 0;
    }
    if (!deplacer(g)) { // sinon si on peut pas encore deplacer ca sera termine
        return 1;
    }
    return 0;
}



int gagner(int **g) {     // gangé s'il un element de la grille = 2048 sinon non  
    for (int i = 0 ; i < TAILLE ; i++) {
        for (int j = 0 ; j < TAILLE ; j++) {
            if (g[i][j] == 2048) { 
                return 1; 
            }
        }
    }
    return 0;
}












