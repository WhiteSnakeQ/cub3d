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

t_hero	*init_hero(int **arr, int x, int y)
{
	t_hero	*to_ret;

	to_ret	= malloc(sizeof(t_hero));
	if (!to_ret)
		emergency_exit_cub3d(MALLFAIL);
	to_ret->x = (float)x;
	to_ret->y = (float)y;
	to_ret->map = arr;
	to_ret->direction = 1.5;
	to_ret->direction_deg = 3.14159 / 4;
	to_ret->distance_view = 30;
	move_hero(0, &to_ret);
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