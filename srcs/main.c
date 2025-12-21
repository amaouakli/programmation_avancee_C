#include "jeu.h"






int main (){

    int ** mat = createGrille();
    initGrille(mat);
	char *saveFile;

	saveFile = initSaveFile();
	printf("%s\n", saveFile);
	saveStateToFile(saveFile, mat);
	saveStateToFile(saveFile, mat);
	saveStateToFile(saveFile, mat);
	mat[0][0] = 2048;
	mat[0][1] = 2;
	affichageGrille(mat);



    liberGrille(mat);
    return 0 ;
}
