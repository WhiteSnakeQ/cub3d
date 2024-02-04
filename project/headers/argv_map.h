#ifndef ARGV_MAP_H
# define ARGV_MAP_H

typedef struct s_argv_map
{
	char				*argv;
	int					size;
	struct s_argv_map	*next;
}				t_argv_map;

#endif