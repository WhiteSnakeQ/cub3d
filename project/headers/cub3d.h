#ifndef CUB3D_H
# define CUB3D_H

# include "map.h"
# include "minimap.h"
# include "env.h"
# include "hero.h"

typedef struct s_cub3d
{
	struct s_map		*map;
	struct s_minimap	*minimap;
	struct s_env		*env;
	struct s_hero		*hero;
}				t_cub3d;

t_cub3d		*init_cub3d( void );
void		clean_cub3d(int mod, t_cub3d **toclean);
float		abs_m(float i);

#endif