#ifndef MINIMAP_H
# define MINIMAP_H

# define DEFMULTP 1

typedef struct s_minimap
{
	int		pixel_multipl;
	void	*image;
}				t_minimap;

void	init_minimap(void *cub);
void	free_minimap(t_minimap **minimap, void *screen);

#endif