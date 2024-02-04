#include "../../headers/argv_map.h"
#include "../../headers/string_work.h"
#include "stdlib.h"

#include "../../headers/ft_printf.h"

void	clean_t_map_argv(void *argv)
{
	t_argv_map	*next;
	t_argv_map	*curr;

	curr = (t_argv_map *)argv;
	while (curr)
	{
		next = curr->next;
		free_string(&curr->argv);
		free(curr);
		curr = next;
	}
}
