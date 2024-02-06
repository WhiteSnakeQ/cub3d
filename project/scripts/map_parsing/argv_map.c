#include "../../headers/argv_map.h"
#include "../../headers/get_next_line.h"
#include "../../headers/string_work.h"

#include "../../headers/ft_printf.h"

static t_argv_map	*new_args(char *str)
{
	t_argv_map	*new;

	if (!str)
		return (NULL);
	new = malloc(sizeof(t_argv_map));
	if (!new || !str)
		return (NULL);
	new->argv = ft_strdup(str, 0);
	new->size = count_worlds(new->argv);
	new->next = NULL;
	return (new);
}

static t_argv_map	*last_list(t_argv_map *list)
{
	if (!list)
		return (list);
	while (list->next)
		list = list->next;
	return (list);
}

void	*make_argv(int fd)
{
	char		*arg;
	t_argv_map	*args;

	arg = del_symbl(get_next_line(fd), "\n");
	args = new_args(arg);
	if (!args)
		return ((void *)args);
	while (arg)
	{
		free_string(&arg);
		arg = del_symbl(get_next_line(fd), "\n");
		if (!ft_strlen(arg))
			continue ;
		last_list(args)->next = new_args(arg);
	}
	close(fd);
	return ((void *)args);
}
