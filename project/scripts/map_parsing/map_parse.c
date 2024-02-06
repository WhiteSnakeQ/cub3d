#include "../../headers/map.h"
#include "../../headers/errors.h"
#include "fcntl.h"

#include "../../headers/ft_printf.h"

static int	check_open(char *f_name)
{
	int	fd;

	fd = open(f_name, O_RDWR);
	if (fd <= -1)
		emergency_exit_cub3d(INVFILE);
	return (fd);
}

static int	*new_arr(int *arr, int new_size)
{
	int	i;
	int	*new;

	i = 0;
	new = malloc(sizeof(int) * new_size);
	if (!new || !arr)
		return (NULL);
	while (i < new_size && (arr[i] != -5 && arr[i] != -2))
	{
		new[i] = arr[i];
		i++;
	}
	if (arr[i] == -2)
		new[i++] = -2;
	while (i < new_size)
		new[i++] = -1;
	free(arr);
	return (new);
}

static void	resize_arrays(int **array, int new_size, int rows)
{
	int	i;

	i = 0;
	while (i < rows)
	{
		array[i] = new_arr(array[i], new_size);
		i++;
	}
}

static int	check_array(t_map *map)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	if (map->coll <= 2 || map->rows <= 2)
		return (0);
	while (y < map->rows)
	{
		x = 0;
		if (!map->map[y])
			return (0);
		while (x < map->coll)
		{
			if (map->map[y][x] == -2)
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

void	map_parse(char *f_name, t_map *map)
{
	int			fd;
	void		*argv;

	fd = check_open(f_name);
	argv = make_argv(fd);
	if (!fill_map_texture(&argv, map))
		emergency_exit_map(MALLFAIL, argv);
	if (!check_required_texture(map->textures_names))
		emergency_exit_map(ENSFTEXTURE, argv);
	if (!check_map_texture(map->textures_names))
		emergency_exit_map(SAMETEXTURE, argv);
	if (!fill_map_int(&argv, map))
		emergency_exit_map(MALLFAIL, argv);
	clean_t_map_argv(argv);
	resize_arrays(map->map, map->coll, map->rows);
	if (!check_array(map))
		emergency_exit_cub3d(INVMAP);
	if (!check_array_close(map))
		emergency_exit_cub3d(NCLOSE);
	// if (!check_colors(map->textures_names))
	// 	emergency_exit_cub3d(NCLOSE);
	// if (!check_textures_exist(map->textures_names))
	// 	emergency_exit_cub3d(NCLOSE);
}
