#include"jeu.h"

static int tailleInt(int n)
{
	int	taille;

	taille = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		n = -n;
	while (n > 0)
	{
		n = (n / 10);
		taille++;
	}
	return (taille);
}


void	affichageGrille(int **g)
{
	int	i;
	int	j;

	i = 0;
	while (i < (TAILLE * 6) + 1)
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
	while (i < (TAILLE * 6) + 1)
	{
		printf("-");
		i++;
	}
	printf("\n");
}
