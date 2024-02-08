#include "../../headers/cub3d.h"
#include "../../headers/errors.h"
#include "../../headers/mlx.h"

t_minimap	*init_minimap()
{
	t_minimap	*minimap;

	minimap = malloc(sizeof(t_minimap));
	if (!minimap)
		emergency_exit_cub3d(MALLFAIL);
	minimap->pixel_multipl = DEFMULTP * 4;
	minimap->start = 0;
	return (minimap);
}

void	free_minimap(t_minimap **minimap)
{
	if (!minimap || !*minimap)
		return ;
	free(*minimap);
	*minimap = NULL;
}
