#include "../../headers/hero.h"
#include "../../headers/errors.h"

char	look_side(int mod, char letter)
{
	static char	side = '\0';

	if (mod == 1)
	{
		side = letter;
		return ('\0');
	}
	else
		return (side);
}

static void	fill_direction(t_hero *h)
{
	char	side;

	side = look_side(0, 'p');
	if (side == 'N')
	{
		h->direction_x = 0;
		h->direction_y = -1;
		h->plane_x = -0.66;
		h->plane_y = 0;
	}
	else if (side == 'S')
	{
		h->direction_x = 0;
		h->direction_y = 1;
		h->plane_x = 0.66;
		h->plane_y = 0;
	}
	else if (side == 'E')
	{
		h->direction_x = -1;
		h->direction_y = 0;
		h->plane_x = 0;
		h->plane_y = 0.66;
	}
	else if (side == 'W')
	{
		h->direction_x = 1;
		h->direction_y = 0;
		h->plane_x = 0;
		h->plane_y = -0.66;
	}
}

t_hero	*init_hero(int **arr, int x, int y)
{
	t_hero	*to_ret;

	to_ret	= malloc(sizeof(t_hero));
	if (!to_ret)
		emergency_exit_cub3d(MALLFAIL);
	to_ret->x = (float)x;
	to_ret->y = (float)y;
	to_ret->map = arr;
	fill_direction(to_ret);
	to_ret->direct_deg = 3.14159 / 4;
	to_ret->distance_view = 30;
	move_hero(0, &to_ret);
	rotate_hero(0, &to_ret, 0.05);
	return (to_ret);
}

void	free_hero(t_hero **hero)
{
	t_hero	*toclen;

	if (!hero || !*hero)
		return ;
	toclen = *hero;
	free(toclen);
	*hero = NULL;
}