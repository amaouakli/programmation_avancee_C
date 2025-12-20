
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