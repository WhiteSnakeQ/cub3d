/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kirrill20030@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 14:45:07 by kreys             #+#    #+#             */
/*   Updated: 2023/07/30 15:29:14 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/string_work.h"
#include <stdlib.h>

int		ft_convert_base2(char *str, char *base);

char	*reverse_string(char *string, int smaller);

int		check_base(char *base, int main_iter, int inr_iter);

void	make_string(long nbr, char *base, char *str)
{
	int		size;

	size = 0;
	while (base[size])
		size++;
	if (nbr / size > 0)
		make_string((nbr / size), base, (str + 1));
	*str = base[nbr % size];
}

int	take_size(long nbr, char *base, int plus)
{
	int		to_ret;
	int		size_b;

	size_b = 0;
	while (base[size_b])
		size_b++;
	to_ret = 2;
	while (nbr > size_b)
	{
		to_ret++;
		nbr /= size_b;
	}
	return (to_ret + plus);
}

char	*to_base_fr_numb(long nbr, char *base, int minus)
{
	int		size_of;
	char	*string;

	if (nbr < 0)
	{
		nbr = -nbr;
		size_of = take_size(nbr, base, 1);
	}
	else
		size_of = take_size(nbr, base, 0);
	string = malloc(sizeof(char) * (size_of));
	make_string(nbr, base, &string[0]);
	if (minus == 1)
		string[size_of - 2] = 45;
	string[size_of - 1] = '\0';
	return (string);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*to_resive;
	char	*to_return;
	long	to_base;
	int		minus;

	minus = 0;
	if (check_base(base_from, 0, 0) <= -1)
		return ((void *)0);
	if (check_base(base_to, 0, 0) <= -1)
		return ((void *)0);
	to_base = ft_convert_base2(nbr, base_from);
	if (to_base == 0)
	{
		to_return = malloc(sizeof(char) * 2);
		to_return[0] = base_to[0];
		to_return[1] = '\0';
		return (to_return);
	}
	if (to_base < 0)
		minus++;
	to_resive = to_base_fr_numb(to_base, base_to, minus);
	to_return = reverse_string(to_resive, 0);
	return (to_return);
}
