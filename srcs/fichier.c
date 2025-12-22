#include"jeu.h"

int	saveStateToFile(char *fileName, int **g, int score)
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
			fprintf(fd, "$%d;\n", score);
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
	while (line[i] != '$')
	{
		if (i > 0)
			i++;
		g[nb_empl / TAILLE][nb_empl % TAILLE] = ft_atoi(& line[i]);
		nb_empl++;
		while (line[i] != ':' && line[i] != '$')
			i++;
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
	{
		printf("could not open file heheheh\n");
		return (-1);
	}
	cr = fgetc(fd);
	line = malloc(sizeof(char *) * 1);
	if (!line)
		return (-1);
	line = "\0";
	while (cr != EOF)
	{
		line = ft_strappend(line, cr);
		if (cr == ';')
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

int **lineToGrille(char *line, int *score)
{
	int		i;
	int		nb_empl;
	int		**g;

	i = 0;
	nb_empl = 0;
	g = createGrille();
	initGrille(g);
	while (line[i] != '$')
	{
		if (i > 0)
			i++;
		g[nb_empl / TAILLE][nb_empl % TAILLE] = ft_atoi(& line[i]);
		nb_empl++;
		while (line[i] != ':' && line[i] != '$')
			i++;
	}
	*score = ft_atoi(& line[i + 1]);
	return (g);
}
int	**recupGrilleEnCours(char *fileName, int *score)
{
	FILE *fd;
	char cr;
	char *line;
	int	**grille;

	fd = fopen(fileName, "r");
	if (!fd)
	{
		printf("could not open file\n");
		return (NULL);
	}
	cr = fgetc(fd);
	line = malloc(sizeof(char *) * 1);
	if (!line)
		return (NULL);
	line = "\0";
	while (cr != EOF)
	{
		line = ft_strappend(line, cr);
		if (cr == ';')
		{
			grille = lineToGrille(line, score);
			free(line);
			line = malloc(sizeof(char *) * 1);
			line = "\0";
		}
		cr = fgetc(fd);
	}
	free(line);
	fclose(fd);
	return (grille);
}
