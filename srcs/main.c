#include "jeu.h"






int main (int argc, char **argv)
{

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
//	affichageGrille(mat);
	//replayGame(argv[1]);
	outputLine(argv[1]);
	//printf("%d\n", atoi( & argv[1][4]));



    liberGrille(mat);
    return 0 ;
}
