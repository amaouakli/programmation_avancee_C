
#include "jeu.h"


int ** createGrille () {     // allocation d'une matrice 4 * 4 
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



void liberGrille (int ** g ){  // free 
    for( int i  = 0 ; i < TAILLE ; i ++ ) {
        free(g[i]);
    }
   free(g);
}


void initGrille ( int ** g ){   // initialisation de la grille avec des 0 
    for ( int i = 0 ; i < TAILLE ; i ++ ){
        for ( int j = 0 ; j < TAILLE ; j++){
            g[i][j] = 0 ;
        }

    }
}


int caseVide ( int **g , int i , int j) {   // renvoie 0  si la case est vide sinon 1 
    int res = 1;
    if ( g[i][j] == 0 ) {
        res = 0 ;
    }  
    return res ;
}


int nbCaseVide ( int **g ){    // compte le nombre de cases vides 
    int cpt  = 0 ;
    for ( int i = 0 ; i  < TAILLE ; i ++  ){
        for( int j = 0 ; j < TAILLE ; j ++){
            if (caseVide (g , i, j ) ){
                cpt ++ ;
            }
        }
    }
    return cpt ;
}


int ajouterTuile (int ** g ){             // ajouter une tuile selon rand 
    int nombreCaseVide = nbCaseVide (g );
    if (nombreCaseVide == 0 ){
        return 0;
    }
    int cpt = 0 ;
    int choix = rand() % nombreCaseVide ;

    for( int i = 0 ; i < TAILLE ; i ++ ){
        for( int j = 0 ; j < TAILLE ; j++){
            if( caseVide (g , i , j)){
                if ( cpt == choix){
                    if (rand() % 100 < AVOIRQ) {
                        g[i][j] = 4;
                    } else {
                        g[i][j] = 2;
                    }
                    return 1 ;
                }
                cpt ++ ;
            }
        }
    }
    return 0 ;
}



void initJeu(int **g, int *score) {   // initialiser le plateau et deux cases 
    initGrille(g);
    ajouterTuile(g);
    ajouterTuile(g);
    *score = 0;
}


// on ecrit le cas ou c'est a gauche ici 

int calcul(int ligne[TAILLE] , int *score) {   // le calule d'un resultat d'un movement 
    int res = 0;
    for (int j = 0 ; j < TAILLE - 1 ; j++) {     
        for (int i = 0 ; i < TAILLE - 1 ; i++) {
            if ( ligne[i] == 0 && ligne[i+1] != 0) { // on echange les elements si l'un est 0 et le suivant est ! nul
                ligne[i] = ligne[i+1] ;
                ligne[i+1] = 0;
                res = 1;
            }
        }
    }
    for (int i = 0 ; i < TAILLE - 1 ; i++) {    // on multiplie les element adjacents = 
        if ( ligne[i] != 0 && ligne[i] == ligne[i+1]) {
            ligne[i] = ligne[i] * 2;
            *score = *score + ligne[i];
            ligne[i+1] = 0;
            res = 1 ;
        }
    }
    
    for (int j = 0 ; j < TAILLE - 1 ; j++) {    // on echange si ya des 0 
        for (int i = 0 ; i < TAILLE - 1 ; i++) {
            if (ligne[i] == 0 && ligne[i+1] != 0) {

                ligne[i] = ligne[i+1] ;
                ligne[i+1] = 0;
                res= 1 ;
            }
        }
    }
    
    return res;
}



void inverserLigne ( int  ligne [TAILLE]){   // fonction qui inverse une ligne 

    for( int i = 0 ; i < TAILLE / 2 ;i ++ ){
        int temp = ligne[i];
        ligne[i] = ligne[ TAILLE - 1 - i];
        ligne[TAILLE - 1 - i ] = temp;
    }

    return ;
}

 
int movGauche(int **g , int *score) {    // extraire uen ligne a la fois et appeler calucl puis recopier 
    int res= 0;
    int temp[TAILLE];
    
    for (int i = 0 ; i < TAILLE ; i++) {
        for (int j = 0 ; j < TAILLE ; j++) {
            temp[j] = g[i][j];
        }
        
        if (calcul(temp , score)) {
            res = 1;
            
            for (int j = 0 ; j < TAILLE ; j++) {
                g[i][j] = temp[j];
            }
        }
    }
    return res;
}










int main (){

    int ** mat = createGrille();
    initGrille(mat);
    

    // affichage pour l'instant  
    for( int i = 0 ; i < 4 ; i ++ ) {
        for( int j = 0 ; j < 4 ; j ++){
            printf("%d ",mat[i][j]);
        }
        printf("\n");
    }
    



    liberGrille(mat);
    return 0 ;
}