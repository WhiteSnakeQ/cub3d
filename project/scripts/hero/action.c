#include "../../headers/hero.h"
#include "../../headers/map_id.h"
#include "math.h"

#include "../../headers/ft_printf.h"

static void	change_vectr(double *x, double *y, float angle)
{
	float	old_x;
	float	old_y;

	old_x = *x;
	old_y = *y;
	*x = old_x * cos(angle) - old_y * sin(angle);
	*y = old_x * sin(angle) + old_y * cos(angle);
}

void	rotate_hero(int side, t_hero **hero, float rh)
{
	static t_hero	*to_oper;
	float			rotate;

	if (hero && *hero)
	{
		to_oper = *hero;
		return ;
	}
	if (side == 1)
		rotate = -rh;
	else
		rotate = rh;
	change_vectr(&to_oper->direction_x, &to_oper->direction_y, rotate);
	change_vectr(&to_oper->plane_x, &to_oper->plane_y, rotate);
}

void	move_hero(float move, t_hero **hero)
{
	static t_hero	*to_oper;
	float			new_x;
	float			new_y;

	if (hero && *hero)
	{
		to_oper = *hero;
		return ;
	}
	to_oper->map[(int)to_oper->y][(int)to_oper->x] = FLOOR;
	new_x = to_oper->x + (-to_oper->direction_x) * move;
	new_y = to_oper->y + (to_oper->direction_y) * move;
	if (to_oper->map[(int)new_y][(int)new_x] != WALL)
	{
		to_oper->x = new_x;
		to_oper->y = new_y;
		to_oper->map[(int)to_oper->y][(int)to_oper->x] = HERO;
	}
	else
		to_oper->map[(int)to_oper->y][(int)to_oper->x] = HERO;
}
