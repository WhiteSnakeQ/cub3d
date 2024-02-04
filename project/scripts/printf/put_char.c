/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_char.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kirrill20030@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 12:10:35 by kreys             #+#    #+#             */
/*   Updated: 2023/11/04 20:19:33 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/ft_printf.h"

void	put_char(char c, t_action **act)
{
	(*act)->txt = malloc(sizeof(char) * 2);
	(*act)->txt[0] = c;
	(*act)->txt[1] = '\0';
	(*act)->s_txt += 1;
	(*act)->act = 'c';
}