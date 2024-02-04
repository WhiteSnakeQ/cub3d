#include "../../headers/map.h"
#include "../../headers/errors.h"
#include "stdlib.h"

t_map	*init_map( void )
{
	t_map	*to_ret;

	to_ret = malloc(sizeof(t_map));
	if (!to_ret)
		emergency_exit_cub3d(MALLFAIL);
	to_ret->coll = 0;
	to_ret->rows = 0;
	to_ret->textures_names = NULL;
	to_ret->map = NULL;
	return (to_ret);
}
