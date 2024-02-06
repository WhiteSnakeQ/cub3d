#include "../../headers/map.h"
#include "../../headers/argv_map.h"
#include "../../headers/string_work.h"
#include "stdlib.h"

#include "../../headers/ft_printf.h"

static t_texture_map	*last_list(t_texture_map *list)
{
	if (!list)
		return (list);
	while (list->next)
		list = list->next;
	return (list);
}

static t_texture_map	*new_texture_name(t_argv_map *argv, int index)
{
	t_texture_map	*new;

	new = malloc(sizeof(t_argv_map));
	if (!new)
		return (new);
	new->argv = ft_split(argv->argv, ' ');
	new->color = 0;
	if (ft_strslen(new->argv) >= 3)
		return(free_strings(new->argv), free(new), NULL);
	if (ft_strlen(new->argv[0]) >= 3)
		return(free_strings(new->argv), free(new), NULL);
	new->size = 2;
	new->index = index;
	new->next = (void *)0;
	return (new);
}

static void	free_one_list(t_argv_map *list)
{
	free_string(&list->argv);
	free(list);
}

static t_argv_map	*free_list(void **argv, t_argv_map *new)
{
	t_argv_map	*to_ret;
	t_argv_map	*next;

	to_ret = (t_argv_map *)(*argv);
	while (to_ret && to_ret != new)
	{
		next = to_ret->next;
		free_one_list(to_ret);
		to_ret = next;
	}
	return (next);
}

int	fill_map_texture(void **argv, t_map *map)
{
	t_argv_map	*curr;
	int			i;

	i = 2;
	map->textures_names = new_texture_name((t_argv_map *)(*argv), i++);
	if (!map->textures_names)
		return (0);
	curr = ((t_argv_map *)(*argv))->next;
	while (curr)
	{
		if (curr->size != 2 || is_digit(curr->argv[0]))
			break ;
		last_list(map->textures_names)->next = new_texture_name(curr, i++);
		curr = curr->next;
	}
	*argv = (void *)free_list(argv, curr);
	return (1);
}
