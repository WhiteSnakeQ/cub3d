#include "../../headers/map.h"
#include "../../headers/string_work.h"
#include "stdlib.h"

t_list_int	*last_list_int(t_list_int *list)
{
	if (!list)
		return (list);
	while (list->next)
		list = list->next;
	return (list);
}

t_list_int	*new_list_int(t_argv_map *argv)
{
	t_list_int	*new;

	new = malloc(sizeof(t_list_int));
	if (!new)
		return (new);
	new->next = (void *)0;
	new->size = ft_strlen(argv->argv);
	new->row = malloc(sizeof(int) * (new->size + 1));
	if (!new->row)
		return (free(new), NULL);
	new->row[new->size] = -5;
	new->str = ft_strdup(argv->argv, 0);
	if (!new->str)
		return (free(new->row), free(new), NULL);
	return (new);
}

int	check_map_texture(t_texture_map *textures)
{
	t_texture_map	*curr;
	t_texture_map	*check;

	curr = textures;
	while (curr)
	{
		check = textures;
		while (check)
		{
			if (check != curr)
			{
				if (curr->argv[0][0] == check->argv[0][0])
					return (0);
			}
			check = check->next;
		}
		curr = curr->next;
	}
	return (1);
}
