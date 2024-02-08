#include "../../headers/string_work.h"
#include "stdlib.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (*(s1 + i) && *(s1 + i) == *(s2 + i))
		i++;
	return (*((unsigned char *)s1 + i) - *((unsigned char *)s2 + i));
}

int	count_symb(char *str, char c)
{
	int	i;
	int	symb;

	i = 0;
	symb = 0;
	while (str[i])
	{
		if (str[i] == c)
			symb++;
		i++;
	}
	return (symb);
}

static int	check_string(long *number_print, char *symbol, int *minus)
{
	int		stop_cheking;

	stop_cheking = 0;
	while (*symbol)
	{
		if (symbol[0] >= '0' && symbol[0] <= '9')
		{
			*number_print *= 10;
			*number_print += symbol[0] - 48;
			stop_cheking++;
		}
		else if (*number_print > 0)
			return (1);
		else if ((symbol[0] == '+' || symbol[0] == '-') && *number_print == 0)
		{
			stop_cheking++;
			if (symbol[0] == '-')
				*minus = -*minus;
		}
		else
			return (-1);
		symbol++;
	}
	return (1);
}

int	ft_atoi(char *str)
{
	long		number_to_print;
	int			minus;

	minus = 1;
	number_to_print = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	check_string(&number_to_print, str, &minus);
	if (minus == -1)
		number_to_print = -number_to_print;
	return (number_to_print);
}

int	str_is_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!is_digit(str[i]))
			return (0);
		i++;
	}
	return (1);
}
