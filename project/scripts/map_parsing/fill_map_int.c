#include "../../headers/map.h"
#include "../../headers/map_id.h"
#include "../../headers/string_work.h"
#include "../../headers/map_id.h"
#include "stdlib.h"

#include "../../headers/ft_printf.h"

static int	return_index(t_texture_map *texture, char letter)
{
	static int	hero = 0;
	char		*str;

	while (texture)
	{
		str = texture->argv[0];
		if (letter == 'N' || letter == 'S')
		{
			if (hero++ == 1)
				return (ERRMAP);
			return (HERO);
		}
		if (letter == 'E' || letter == 'W')
		{
			if (hero++ == 1)
				return (ERRMAP);
			return (HERO);
		}
		if (str[0] == letter)
			return (texture->index);
		texture = texture->next;
	}
	return (ERRMAP);
}

static int	convert(t_list_int *list, t_map *map)
{
	int	i;

	i = 0;
	while (list->str[i])
	{
		if (list->str[i] == '0')
			list->row[i] = FLOOR;
		else if (list->str[i] == '1')
			list->row[i] = WALL;
		else if (list->str[i] == ' ')
			list->row[i] = EMPTY;
		else
			list->row[i] = return_index(map->textures_names, list->str[i]);
		if (list->row[i] == ERRMAP)
			return (0);
		i++;
	}
	return (1);
}

static void	convert_list_int(t_list_int *argv, t_map *map)
{
	t_list_int	*first;
	t_list_int	*next;
	int			i;

	i = 0;
	first = argv;
	while (argv)
	{
		i++;
		convert(argv, map);
		argv = argv->next;
	}
	map->map = malloc(sizeof(int *) * i);
	if (!map->map)
		return ;
	i = 0;
	while (first)
	{
		next = first->next;
		map->map[i++] = first->row;
		free_string(&first->str);
		free(first);
		first = next;
	}
}

int	fill_map_int(void **argv, t_map *map)
{
	t_argv_map	*curr;
	t_list_int	*list_int;
	int			pre_coll;

	if (!argv || !*argv)
		return (0);
	curr = ((t_argv_map *)(*argv))->next;
	list_int = new_list_int((t_argv_map *)(*argv));
	if (!list_int)
		return (0);
	map->coll = ft_strlen(((t_argv_map *)(*argv))->argv);
	map->rows = 1;
	while (curr)
	{
		last_list_int(list_int)->next = new_list_int(curr);
		pre_coll = ft_strlen(curr->argv);
		if (map->coll < pre_coll)
			map->coll = pre_coll;
		map->rows++;
		curr = curr->next;
	}
	convert_list_int(list_int, map);
	return (1);
}
