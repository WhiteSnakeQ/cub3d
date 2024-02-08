#ifndef HERO_H
# define HERO_H

#include "cub3d.h"

typedef struct s_hero
{
	float	x;
	float	y;
	float	direction;
	float	direction_deg;
	float	distance_view;
	int		**map;
}				t_hero;

t_hero	*init_hero(int **arr, int x, int y);

void	move_hero(float move, t_hero **hero);

void	free_hero(t_hero **hero);

char	look_side(int mod, char letter);

#endif