#include "../../headers/string_work.h"
#include "stdlib.h"

#include "../../headers/ft_printf.h"

char	*ft_strchr(const char *src, int symbol)
{
	while (*src)
	{
		if (*src)
			if (*src == (char)symbol)
				return ((char *)src);
		src++;
	}
	if (symbol == '\0')
		return ((char *)src);
	return (0);
}

static size_t	counter(char const *s, char c)
{
	size_t	counts;

	if (!s || !*s)
		return (0);
	counts = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			counts++;
		while (*s != c && *s)
			s++;
	}
	return (counts);
}

char	*ft_substr(char const *s, unsigned int start, int len)
{
	char	*src;
	int		size;
	int		i;

	i = 0;
	size = 0;
	if (s == NULL)
		return (NULL);
	src = malloc(sizeof(*s) * (len + 1));
	if (src == NULL)
		return (NULL);
	while (len > size && s[i])
	{
		if (i >= (int)start)
			src[size++] = s[i];
		i++;
	}
	src[size] = 0;
	return (src);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	size_t	lenss;
	int		i;

	str = (char **)malloc((counter(s, c) + 1) * sizeof(char *));
	if (!s || !str)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
		{
			if (!ft_strchr(s, c))
				lenss = ft_strlen(s);
			else
				lenss = ft_strchr(s, c) - s;
			str[i++] = ft_substr(s, 0, lenss);
			s += lenss;
		}
	}
	str[i] = NULL;
	return (str);
}

int	count_worlds(char *str)
{
	int	i;
	int	worlds;

	i = 0;
	worlds = 0;
	while (str && str[i])
	{
		while (str[i] && ((str[i] >= 9 && str[i] <= 13) || str[i] == ' '))
			i++;
		if (str[i])
			worlds++;
		while (str[i] && ((str[i] < 9 || str[i] > 13) && str[i] != ' '))
			i++;
	}
	return (worlds);
}
