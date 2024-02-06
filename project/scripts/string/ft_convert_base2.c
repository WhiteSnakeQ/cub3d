/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kirrill20030@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 14:45:07 by kreys             #+#    #+#             */
/*   Updated: 2023/07/27 15:19:56 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/string_work.h"
#include <stdlib.h>

int	found_number(int size_of_str, char *string, char *base)
{
	int		our_numb;
	int		multiplay;
	int		iter_base;
	int		size_base;

	size_base = 0;
	iter_base = 0;
	while (base[size_base])
		size_base++;
	while (string[0] != base[iter_base])
	{
		if (base[iter_base] == '\0')
			return (0);
		iter_base++;
	}
	multiplay = 1;
	while (size_of_str-- > 0)
		multiplay *= size_base;
	our_numb = iter_base * multiplay;
	return (our_numb);
}

char	*reverse_string(char *string, int smaller)
{
	int		index;
	int		size_str;
	char	*to_return;

	index = 0;
	size_str = 0;
	while (string[size_str])
		size_str++;
	to_return = malloc(sizeof(char) * (size_str + 1));
	size_str -= 1;
	while (size_str >= smaller)
		to_return[index++] = string[size_str--];
	to_return[index] = '\0';
	free(string);
	return (to_return);
}

int	check_string(char *string, char *base, int iter_main)
{
	int		iter_base;
	int		size_to_ret;

	size_to_ret = 0;
	while (string[iter_main])
	{
		if (string[0] == '-' || string[0] == '+')
		{
			string++;
			continue ;
		}
		else if (string[iter_main])
		{
			iter_base = 0;
			while (base[iter_base] && size_to_ret == iter_main)
			{
				if (string[iter_main] == base[iter_base++])
					size_to_ret++;
			}
		}
		iter_main++;
		if (size_to_ret != iter_main)
			return (size_to_ret);
	}
	return (size_to_ret);
}

int	check_base(char *base, int main_iter, int inr_iter)
{
	int		same;

	if (base[0] == '\0' || base[1] == '\0')
		return (-1);
	main_iter = 0;
	while (base[main_iter])
	{
		if (base[main_iter] == '+' || base[main_iter] == '-')
			return (-1);
		if (base[main_iter] >= 127 || base[main_iter] <= 32)
			return (-1);
		inr_iter = 0;
		same = 0;
		while (base[inr_iter])
		{
			if (base[main_iter] == base[inr_iter++])
				same++;
			if (same >= 2)
				return (-1);
		}
		main_iter++;
	}
	if (main_iter <= 1)
		return (-1);
	return (0);
}

int	ft_convert_base2(char *str, char *base)
{
	long		our_number;
	int			size_of_str;
	int			minus;

	if (check_base(base, 0, 0) <= -1)
		return (0);
	minus = 1;
	our_number = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	size_of_str = check_string(str, base, 0);
	if (size_of_str <= 0)
		return (0);
	while ((*str == '-' || *str == '+') && str++ != (void *)0)
		if (*(str - 1) == '-')
			minus = -minus;
	while (size_of_str-- > 0)
		our_number += found_number(size_of_str, (str++), base);
	if (our_number == 0)
		return (0);
	if (minus == -1)
		our_number = -our_number;
	return (our_number);
}
