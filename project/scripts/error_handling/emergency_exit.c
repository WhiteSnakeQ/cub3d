#include "../../headers/errors.h"
#include "../../headers/cub3d.h"
#include "../../headers/map.h"

int	emergency_exit_cub3d(char *message)
{
	error_message(message);
	clean_cub3d(0, NULL);
	exit(0);
}

void	emergency_exit_map(char *message, void *argv)
{
	free_t_map_argv(argv);
	emergency_exit_cub3d(message);
}
