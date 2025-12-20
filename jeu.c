

// creation/liberation/ajout/movement 





#include<stdio.h>
#include<stdlib.h>
#include<error.h>


int ** createGrid ( int taille ) {
    int ** g = (int ** ) malloc ( taille * sizeof(int *)) ;
    if (!g )  {
        perror("Erreur d'allocation mémoire");
        exit(-1); 

    }
    for ( int  i = 0 ; i < taille ; i ++ ){
        g[i] = ( int * )malloc (taille * sizeof ( int ));
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


void initGrid ( int ** g , int taille ){
    for ( int i = 0 ; i < taille ; i ++ ){
        for ( int j = 0 ; j < taille ; j++){
            g[i][j] = 0 ;
        }

    }
}


void liberGrid (int ** g , int taille){
    for( int i  = 0 ; i < taille ; i ++ ) {
        free(g[i]);
    }
   free(g);
}