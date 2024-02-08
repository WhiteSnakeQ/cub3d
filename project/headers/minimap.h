#ifndef MINIMAP_H
# define MINIMAP_H

# define DEFMULTP 3

typedef struct s_minimap
{
	int		pixel_multipl;
	int		start;
}				t_minimap;

t_minimap	*init_minimap(void);
void		free_minimap(t_minimap **minimap);

#endif
