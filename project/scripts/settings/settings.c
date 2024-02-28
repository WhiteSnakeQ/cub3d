#include "../../headers/settings.h"
#include "../../headers/errors.h"
#include "../../headers/key.h"
#include "../../headers/loop.h"
#include "../../headers/hero.h"

#include "../../headers/ft_printf.h"

void	hero_setup(t_cub3d *cub)
{
	int		y;
	int		x;
	int		spawn;

	spawn = 0;
	y = 0;
	x = 0;
	while (y < cub->map->rows)
	{
		x = 0;
		while (x < cub->map->coll)
		{
			if (cub->map->map[y][x] == -10)
			{
				if (!cub->hero)
					cub->hero = init_hero(cub->map->map, x, y);
				spawn++;
				break ;
			}
			x++;
		}
		y++;
	}
	if (spawn == 0)
		emergency_exit_cub3d(INVMAP);
}

void	setup_all(t_cub3d *cub)
{
	cub->minimap->start = HEIGHT - (cub->map->rows * cub->minimap->pixel_multipl);
	key_setup(cub);
	hero_setup(cub);
	mlx_loop_hook(cub->env->window, &loop, (void *)cub);
	mlx_loop(cub->env->window);
}
