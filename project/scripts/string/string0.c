#include "../../headers/string_work.h"
#include "stdlib.h"

int	ft_strlen(const char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strslen(char **str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	free_string(char **str)
{
	if (*str)
		free(*str);
	*str = NULL;
}

void	*free_strings(char **strs)
{
	int	size;
	int	i;

	i = 0;
	size = ft_strslen(strs);
	while (i < size)
		free_string(&strs[i++]);
	free(strs);
	return (NULL);
}

int	strcmp_back(char *str, char *str2, unsigned int n)
{
	unsigned int	size1;
	unsigned int	size2;
	unsigned int	i;

	if (!str || !str2)
		return (0);
	size1 = ft_strlen(str);
	size2 = ft_strlen(str2);
	if (size1 < n || size2 < n)
		return (0);
	i = 0;
	while (i < n + 1)
	{
		if (str[size1 - i] != str2[size2 - i])
			return (0);
		i++;
	}
	return (1);
}
