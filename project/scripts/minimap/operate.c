#include "../../headers/cub3d.h"
#include "../../headers/errors.h"
#include "../../headers/mlx.h"

void	init_minimap(void *cub_void)
{
	t_cub3d	*cub;

	cub = (t_cub3d *)cub_void;
	cub->minimap = malloc(sizeof(t_minimap));
	if (!cub->minimap)
		emergency_exit_cub3d(MALLFAIL);
	cub->minimap->pixel_multipl = DEFMULTP;
	cub->minimap->image = mlx_new_image(cub->env->window, cub->map->coll, cub->map->rows);
	if (!cub->minimap->image)
		emergency_exit_cub3d(MALLFAIL);
}

void	free_minimap(t_minimap **minimap, void *window)
{
	t_minimap	*clean;

	
	if (!minimap || !*minimap)
		return ;
	clean = *minimap;
	if (clean->image)
		mlx_destroy_image(window, clean->image);
	*minimap = NULL;
}

int	refresh_minimap(t_cub3d *cub)
{
	(void)cub;
	return (2);
}
