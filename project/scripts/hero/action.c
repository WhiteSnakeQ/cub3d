#include "../../headers/hero.h"
#include "../../headers/map_id.h"
#include "math.h"

#include "../../headers/ft_printf.h"

void	move_hero(float move, t_hero **hero)
{
	static t_hero	*to_oper;

	if (hero && *hero)
	{
		to_oper = *hero;
		return ;
	}
	to_oper->map[(int)to_oper->y][(int)to_oper->x] = FLOOR;
	to_oper->x += move * sinf(to_oper->direction);
	to_oper->y += move * cosf(to_oper->direction);
	if (to_oper->map[(int)to_oper->y][(int)to_oper->x] == WALL)
	{
		to_oper->x -= move * sinf(to_oper->direction);
		to_oper->y -= move * cosf(to_oper->direction);
	}
	to_oper->map[(int)to_oper->y][(int)to_oper->x] = HERO;
}
