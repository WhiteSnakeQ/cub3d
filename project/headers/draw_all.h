#ifndef DRAW_ALL_H
# define DRAW_ALL_H

# include "map.h"

# define WE 50
# define EA 51
# define SO 52
# define NO 53

typedef struct s_color
{
	int		red;
	int		green;
	int		blue;
	int		t;
}		t_color;

typedef struct s_point
{
	double	x;
	double	y;
}			t_point;

typedef struct s_pixel
{
	double	x;
	double	y;
	double	color;
}			t_pixel;


typedef struct s_draw_all
{
	int				x;
	double			start;
	double			end;
	double			dir;
	double			dir_lock;
	double			pos_x;
	double			pos_y;
	double			offset_from_center;
	double			direction_x;
	double			direction_y;
	double			grid_x;
	double			grid_y;
	double			step_x;
	double			step_y;
	double			near_bound_x;
	double			near_bound_y;
	double			dist_to_wall;
	t_texture_map	*texture;
}				t_draw_all;

#endif