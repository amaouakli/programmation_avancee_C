#include "jeu.h"






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
