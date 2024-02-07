#include "../../headers/map.h"
#include "../../headers/string_work.h"
#include "stdlib.h"

#include "../../headers/ft_printf.h"

static void	free_arr_int(int **arr, int size)
{
	int	i;

	i = 0;
	if (!arr)
		return ;
	while (i < size)
	{
		if (!arr[i])
			return ;
		free(arr[i++]);
	}
	free(arr);
}

static void	free_textur_list(t_texture_map *list)
{
	t_texture_map	*next;

	while (list)
	{
		next = list->next;
		free_strings(list->argv);
		free(list);
		list = next;
	}
}

void	free_map(t_map **toclean)
{
	t_map	*map;

	map = *toclean;
	free_arr_int(map->map, map->rows);
	free_textur_list(map->textures_names);
	free(map);
	*toclean = NULL;
}
