#include"jeu.h"

static int tailleInt(int n)
{
	return ((n / 10) + 2);
}


void	affichageGrille(int **g)
{
	int	i;
	int	j;

	i = 0;
	while (i < (TAILLE * 5) + 1)
	{
		printf("-");
		i++;
	}
	printf("\n");
	i = 0;
	while (i < (TAILLE * TAILLE))
	{
		j = 0;
		printf("|");
		while (j < 5 - tailleInt(g[i / TAILLE][i % TAILLE]))
		{
			printf(" ");
			j++;
		}
		printf("%d", g[i / TAILLE][i % TAILLE]);
		if ((i % TAILLE) == (TAILLE - 1))
			printf("|\n");
		i++;
	}
	i = 0;
	while (i < (TAILLE * 5) + 1)
	{
		printf("-");
		i++;
	}
	printf("\n");
}
