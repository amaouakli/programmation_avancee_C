#include "jeu.h"

int main(int argc, char **argv)
{
    int **g = createGrille();
    int score = 0;
    char clique;
    int move = 0;
    char *saveFile;
	char mode;

    srand(time(NULL));
    initJeu(g, &score);
    
    if (argc == 2)
	{
		saveFile = argv[1];
		score = 0;
		g = recupGrilleEnCours(saveFile, & score);
		mode = 'c';
	}
	else
	{
    	saveFile = initSaveFile(); 
		mode = 'n';
	}
	printf("\033[H\033[J");

    while (1) 
    {
        printf("Score : %d\n", score);
        affichageGrille(g);

        if (gagner(g)) {
            printf("Félicitations!\n");
            break;
        }
        if (estTermine(g)) {
            printf("C'est mal passé hehe  dommage \n");
            break;
        }

        printf("Tapez (g:gauche, d:droite, h:haut, b:bas, q:Quitter): ");
        if (scanf(" %c", &clique) != 1) break;
        move = 0;
        if (clique == 'g' || clique == 'G')
            move = movGauche(g, &score);
        else if (clique == 'd' || clique == 'D')
            move = movDroite(g, &score);
        else if (clique == 'h' || clique == 'H')
            move = enHaut(g, &score);
        else if (clique == 'b' || clique == 'B')
            move = enBas(g, &score);
        else if (clique == 'q' || clique == 'Q')
            break;
        if (move) 
        {
            ajouterTuile(g);
            saveStateToFile(saveFile, g, score);
        }
    }
    printf("Fin de partie: %s\n", saveFile);
	printf("Voulez-vous revoir la partie ? (y/n)\n");
	scanf(" %c", &clique);
	if (mode == 'c')
		if (clique == 'y')
			replayGame(saveFile);
	if (mode == 'n')
	{
		if (clique == 'y')
			replayGame(ft_strjoin("savefiles/", saveFile));
    	free(saveFile);
	}
    liberGrille(g);
    return 0;
}

