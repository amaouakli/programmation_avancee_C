#include"jeu.h"

int	saveStateToFile(char *fileName, int **g)
{
	FILE	*fd;
	int		i;

	fd = fopen(ft_strjoin("../savefiles/\0", fileName), "a");
	if (!fd)
		return (-1);
	while (i < (TAILLE * TAILLE))
	{
		fprintf(fd, "%d", g[i / TAILLE][i % TAILLE]);
		printf("%d", g[i / TAILLE][i % TAILLE]);

		if (i < (TAILLE * TAILLE - 1))
		{
			fprintf(fd, "-");
			printf("-");
		}
		else 
		{
			fprintf(fd, "$\n");
			printf("$\n");
		}
		i++;
	}
	fclose(fd); 
	return (1);
}


/*
int main()
{
	int **g;

	g = createGrille();
	initGrille(g);
	saveStateToFile("fileTest1", g);

	return (0);
}
*/
// fonctions de chargement 
