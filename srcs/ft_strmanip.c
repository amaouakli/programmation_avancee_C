#include"jeu.h"

size_t	ft_strlen(const char *a)
{
	int		i;
	char	*s;

	i = 0;
	s = (char *)a;
	while (s[i] != 0)
	{
		i++;
	}
	return ((size_t)i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ret;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	ret = malloc(sizeof(*ret) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (ret == NULL)
		return (0);
	while (i < ft_strlen(s1))
	{
		ret[i] = s1[i];
		i++;
	}
	while (i < (ft_strlen(s1) + ft_strlen(s2)))
	{
		ret[i] = s2[i - ft_strlen(s1)];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

