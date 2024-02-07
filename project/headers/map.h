#ifndef MAP_H
# define MAP_H

# include "lists.h"
# include "argv_map.h"

# define WIDTH 900
# define HEIGHT 1024

typedef struct s_texture_map
{
	int						size;
	int						index;
	int						color;
	char					**argv;
	struct s_texture_map	*next;
}				t_texture_map;

typedef struct s_map
{
	int						rows;
	int						coll;
	int						**map;
	struct s_texture_map	*textures_names;
}				t_map;

t_map		*init_map( void );

int			fill_map_texture(void **argv, t_map *map);
int			fill_map_int(void **argv, t_map *map);
int			check_array_close(t_map *map);
int			check_map_texture(t_texture_map *textures);
int			check_required_texture(t_texture_map *textures);
int			check_colors(t_texture_map *textures);
int			last_check_map(t_texture_map *textures);
int			check_textures_exist(t_texture_map *textures);

void		free_map(t_map **toclean);
void		free_t_map_argv(void *argv);
void		map_parse(char *f_name, t_map *map);
void		*make_argv(int fd);

t_list_int	*last_list_int(t_list_int *list);
t_list_int	*new_list_int(t_argv_map *argv);

#endif