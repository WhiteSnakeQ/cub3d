#include "../../headers/map.h"
#include "../../headers/map_id.h"

#include "../../headers/ft_printf.h"

static int	check_f_l_row(int *arr, int *arr2, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if ((arr[i] != WALL && arr[i] != EMPTY) || (arr2[i] != WALL && arr2[i] != EMPTY))
			return (0);
		i++;
	}
	return (1);
}

static int	check_f_l_coll(t_map *map, int last_coll, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (map->map[i][0] != WALL && map->map[i][0] != EMPTY)
			return (0);
		if (map->map[i][last_coll] != WALL && map->map[i][last_coll] != EMPTY)
			return (0);
		i++;
	}
	return (1);
}

static int	check_inside(t_map *map, int rows, int coll)
{
	int	y;
	int	x;

	y = 1;
	while (y < rows)
	{
		x = 1;
		while (x < coll)
		{
			if (map->map[y][x] == 0)
			{
				if (map->map[y][x + 1] == EMPTY || map->map[y][x - 1] == EMPTY)
					return (0);
				if (map->map[y + 1][x] == EMPTY || map->map[y - 1][x] == EMPTY)
					return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
}

int	check_array_close(t_map *map)
{
	if (!check_f_l_row(map->map[0], map->map[map->rows - 1], map->coll))
		return (0);
	if (!check_f_l_coll(map, map->coll - 1, map->rows))
		return (0);
	if (!check_inside(map, map->rows - 1, map->coll - 1))
		return (0);
	return (1);
}
