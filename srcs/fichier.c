#include"jeu.h"

int	saveStateToFile(char *fileName, int **g)
{
	FILE	*fd;
	int		i;

	fd = fopen(ft_strjoin("savefiles/", fileName), "a");
	if (!fd)
		return (-1);
	i = 0;
	while (i < (TAILLE * TAILLE))
	{
		fprintf(fd, "%d", g[i / TAILLE][i % TAILLE]);
		if (i < (TAILLE * TAILLE - 1))
			fprintf(fd, "-");
		else 
			fprintf(fd, "$\n");
		i++;
	}
	fclose(fd); 
	return (1);
}

char *initSaveFile()
{
    time_t tm;
	char *date__;
	char *ret;

	tm = time(NULL);
	date__ = ctime(& tm);
	ft_str_replace(date__, ' ', '_');
	ft_str_replace(date__, '\n', '\0');
	ret = ft_strjoin(date__, ".txt");
	return (ret);
}



int replayGame(char *fileName)
{
	FILE *fd;

	fd = fopen(fileName, "r");

	fclose(fd);
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
