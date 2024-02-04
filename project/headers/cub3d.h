#ifndef CUB3D_H
# define CUB3D_H

# include "map.h"

typedef struct s_cub3d
{
	struct s_map	*map;
}				t_cub3d;

t_cub3d		*init_cub3d( void );
void		clean_cub3d(int mod, t_cub3d **toclean);

#endif