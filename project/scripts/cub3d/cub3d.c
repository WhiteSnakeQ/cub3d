#include "../../headers/cub3d.h"
#include "../../headers/errors.h"
#include "../../headers/string_work.h"

int	main(int argc, char **argv)
{
	t_cub3d	*cub3d;
	int		x;
	int		y;

	if (argc != 2)
		return (error_message(WRNBARG));
	if (!strcmp_back(argv[1], ".cub", 4))
		return (error_message(INVFORM));
	cub3d = init_cub3d();
	map_parse(argv[1], cub3d->map);
	y = 0;
	while (y < cub3d->map->rows)
	{
		x = 0;
		while (x < cub3d->map->coll)
		{
			ft_printf(2, "%d ", cub3d->map->map[y][x]);
			x++;
		}
		ft_printf(2, "\n");
		y++;
	}
	clean_cub3d(0, NULL);
	return (0);
}
