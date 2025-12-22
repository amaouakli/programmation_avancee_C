#include "jeu.h"

static int	ft_taille(long int n)
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

static void	fill(char *ret, long int n, int taille)
{
	int	i;

	i = taille;
	if (n == 0)
		ret[0] = '0';
	while (i >= 0 && n > 0)
	{
		ret[i - 1] = 48 + n % 10;
		i--;
		n = n / 10;
	}
}

char	*ft_itoa(int n)
{
	int		taille;
	char	*ret;

	taille = ft_taille((long)n);
	if (n < 0)
	{
		ret = malloc (sizeof(*ret) * (taille + 2));
		if (!ret)
			return (NULL);
		ret[0] = '-';
		fill(ret + 1, -((long)n), taille);
		ret[taille + 1] = '\0';
	}
	else
	{
		ret = malloc(sizeof(*ret) * (taille + 1));
		if (!ret)
			return (NULL);
		fill(ret, (long)n, taille);
		ret[taille] = '\0';
	}
	return (ret);
}

int	ft_atoi(const char *nprt)
{
	long int	compt;
	int			signe;
	int			i;
	char		*str;

	str = (char *)nprt;
	signe = 1;
	i = 0;
	compt = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signe = -signe;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		compt = compt * 10 + str[i] - '0';
		i++;
	}
	compt = compt * signe;
	return (compt);
}
