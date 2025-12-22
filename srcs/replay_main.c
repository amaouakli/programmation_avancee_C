#include"jeu.h"

int replayMode(char *fileName, char *action)
{
	FILE *fd;
	char cr;
	char *line;

	fd = fopen(fileName, "r");
	if (!fd)
	{
		printf("could not open file\n");
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
		if (cr == '$')
		{
			outputLine(line);
			scanf(" %c", action);
			free(line);
			line = malloc(sizeof(char *) * 1);
			line = "\0";
		}
		if (*action == 'n')
			cr = fgetc(fd);
		else 
			cr = EOF;
	}
	fclose(fd);
	return (1);
}

int main(int argc, char **argv)
{
	int		stop;
	char	action;

	stop = 0;
	printf("Bienvenue en replay mode :\nVous avez chargé la sauvegarde %s\n", argv[1]);
		printf("Pour passer a l'étape d'apres, entrez 'n'. Pour quitter, entrez 'q'\n");
	while (stop != 1)
	{
		scanf(" %c", &action);
		if (action == 'n')
			replayMode(argv[1], &action);
		if (action == 'q')
		{
			printf("Au revoir !\n");
			stop = 1;
		}
	}
		
	return (0);
}
