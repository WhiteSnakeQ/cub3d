#include "../../headers/string_work.h"
#include "stdlib.h"

char	*ft_strdup(char *src, int size)
{
	char	*s;
	int		i;

	i = 0;
	if (!src)
		return (NULL);
	while (src[i])
		i++;
	if (size > 0)
		i = size;
	else
		size = i;
	s = malloc((sizeof(char) * i) + 1);
	if (s == NULL)
		return (s);
	i = 0;
	while (i < size)
	{
		s[i] = src[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

static int	cmp_one(char *str, char symb)
{
	int	size_s;

	size_s = 0;
	while (str[size_s])
	{
		if (str[size_s] == symb)
			return (-1);
		size_s++;
	}
	return (1);
}

static int	calc_size_del(char *str, char *symbl)
{
	int	size;
	int	real_size;

	size = -1;
	real_size = 0;
	if (!str)
		return (0);
	while (str[++size])
	{
		if (cmp_one(symbl, str[size]) == 1)
			real_size++;
	}
	return (real_size);
}

char	*del_symbl(char *str, char *symbl)
{
	int		size;
	int		i;
	char	*new_str;

	if (!str)
		return (NULL);
	i = -1;
	size = calc_size_del(str, symbl);
	new_str = malloc(sizeof(char) * (size + 1));
	if (!new_str)
		return (free_string(&str), NULL);
	new_str[size] = '\0';
	size = 0;
	while (str[++i])
	{
		if (cmp_one(symbl, str[i]) == 1)
			new_str[size++] = str[i];
	}
	free_string(&str);
	return (new_str);
}

int	is_digit(char symb)
{
	if (symb >= '0' && symb <= '9')
		return (1);
	return (0);
}
