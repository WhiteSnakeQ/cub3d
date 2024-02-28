#include "../../headers/cub3d.h"
#include "stdlib.h"

#include "../../headers/ft_printf.h"

void	clean_cub3d(int mod, t_cub3d **toclean)
{
	static t_cub3d	*cub3d;

	if (mod == 1)
	{
		cub3d = *toclean;
		return ;
	}
	free_map(&cub3d->map, cub3d->env->window);
	free_minimap(&cub3d->minimap);
	free_env(&cub3d->env);
	free_hero(&cub3d->hero);
	free(cub3d);
}
