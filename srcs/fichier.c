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
			fprintf(fd, ":");
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


void outputLine(char *line)
{
	int		i;
	int		nb_empl;
	int		**g;

	i = 0;
	nb_empl = 0;
	g = createGrille();
	initGrille(g);
	affichageGrille(g);
	while (line[i] != '$')
	{
		g[nb_empl / TAILLE][nb_empl % TAILLE] = atoi(& line[i]); 															//TODO
		nb_empl++;
		while (line[i] != ':' && line[i] != '$')
		{
			i++;
			printf("once\n");
		}
	}
	affichageGrille(g);
}


int replayGame(char *fileName)
{
	FILE *fd;
	char cr;
	char *line;

	fd = fopen(fileName, "r");
	if (!fd)
		return (-1);
	cr = fgetc(fd);
	line = malloc(sizeof(char *) * 1);
	if (!line)
		return (-1);
	line = "\0";
	while (cr != EOF)
	{
		line = ft_strappend(line, cr);
		if (cr == '$')
		{
			outputLine(line);
			free(line);
			line = malloc(sizeof(char *) * 1);
			line = "\0";
		}
		cr = fgetc(fd);
	}
	free(line);
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
