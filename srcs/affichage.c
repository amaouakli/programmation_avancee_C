#include"jeu.h"

static int tailleInt(int n)
{
	int	taille;

	taille = 0; // si le nombre est 0, il occupe 1 caractère
	if (n == 0)
		return (1);
	if (n < 0) // on gere les cas ou le nombre est negatif 
		n = -n;
	while (n > 0)  //sinon, on divise par 10 jusqu'à ce que le quotient soit 0
	{
		n = (n / 10);
		taille++; // et on augmente la taille par 1 
	}
	return (taille);
}


void	affichageGrille(int **g) // affichage de la grille 
{
	int	i;
	int	j;

	i = 0;
	while (i < (TAILLE * 6) + 1) // On calcule la largeur tq chaque case fait 5 caractères + le séparateur
	{
		printf("-");
		i++;
	}
	printf("\n");
	i = 0;
	while (i < (TAILLE * TAILLE)) // On utilise une boucle unique de 0 à 15 pour une matrice 4 * 4 
	{
		j = 0;
		printf("|");
		while (j < 5 - tailleInt(g[i / TAILLE][i % TAILLE])) // On calcule combien d'espaces mettre pour que le nombre soit toujours aligné
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
	while (i < (TAILLE * 6) + 1) // bordure de bas
	{
		printf("-");
		i++;
	}
	printf("\n");
}
