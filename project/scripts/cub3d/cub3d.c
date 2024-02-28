#include "../../headers/cub3d.h"
#include "../../headers/errors.h"
#include "../../headers/string_work.h"
#include "../../headers/settings.h"

float	abs_m(float i)
{
	if (i < 0)
		return (-i);
	return (i);
}

int	main(int argc, char **argv)
{
	t_cub3d	*cub3d;

	if (argc != 2)
		return (error_message(WRNBARG));
	if (!strcmp_back(argv[1], ".cub", 4))
		return (error_message(INVFORM));
	cub3d = init_cub3d();
	map_parse(argv[1], cub3d->map, cub3d->env);
	setup_all(cub3d);
	return (0);
}
