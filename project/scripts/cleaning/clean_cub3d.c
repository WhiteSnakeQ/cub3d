#include "../../headers/cub3d.h"
#include "stdlib.h"

void	clean_cub3d(int mod, t_cub3d **toclean)
{
	static t_cub3d	*cub3d;

	if (mod == 1)
	{
		cub3d = *toclean;
		return ;
	}
	clean_map(&cub3d->map);
	free(cub3d);
}
