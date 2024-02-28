#ifndef HERO_H
# define HERO_H

#include "cub3d.h"

typedef struct s_hero
{
	double	x;
	double	y;
	double	direction_x;
	double	direction_y;
	double	plane_x;
	double	plane_y;
	double	direct_deg;
	double	distance_view;
	int		**map;
}				t_hero;

t_hero	*init_hero(int **arr, int x, int y);

void	move_hero(float move, t_hero **hero);
void	rotate_hero(int side, t_hero **hero, float rh);

void	free_hero(t_hero **hero);

char	look_side(int mod, char letter);

#endif