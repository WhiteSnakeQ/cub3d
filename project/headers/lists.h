#ifndef LISTS_H
# define LISTS_H

typedef struct s_list_int
{
	char				*str;
	int					*row;
	int					size;
	struct s_list_int	*next;
}				t_list_int;

#endif