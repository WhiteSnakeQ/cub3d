#include "../../headers/cub3d.h"
#include "../../headers/errors.h"
#include "stdlib.h"

t_cub3d	*init_cub3d( void )
{
	t_cub3d	*to_ret;

	to_ret = malloc(sizeof(t_cub3d));
	if (!to_ret)
		emergency_exit_cub3d(MALLFAIL);
	to_ret->map = NULL;
	clean_cub3d(1, &to_ret);
	to_ret->map = init_map();
	return (to_ret);
}
