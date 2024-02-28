#include "../../headers/cub3d.h"
#include "../../headers/loop.h"
#include "../../headers/mlx.h"
#include "../../headers/string_work.h"
#include "../../headers/map_id.h"
#include "../../headers/draw_all.h"

#include "unistd.h"
#include "stdio.h"
#include "math.h"
#include "../../headers/ft_printf.h"
#include "../../headers/errors.h"

void	put_pix_2(int x, int y, t_env *env, t_color color)
{
	env->image_str[(x + (y * WIDTH)) * 4] = color.blue;
	env->image_str[((x + (y * WIDTH)) * 4) + 1] = color.green;
	env->image_str[((x + (y * WIDTH)) * 4) + 2] = color.red;
	env->image_str[((x + (y * WIDTH)) * 4) + 3] = color.t;
}

void	put_pix(int x, int y, t_env *env, int color)
{
	env->image_str[(x + (y * WIDTH)) * 4] = (color) & 0xFF;
	env->image_str[((x + (y * WIDTH)) * 4) + 1] = (color >> 8) & 0xFF;
	env->image_str[((x + (y * WIDTH)) * 4) + 2] = (color >> 16) & 0xFF;
	env->image_str[((x + (y * WIDTH)) * 4) + 3] = (color >> 24);
}

void	some(t_cub3d *cub, t_draw_all *d_all)
{
	(void)cub;
	if (d_all->direction_x < 0)
	{
		d_all->step_x = -1;
		d_all->near_bound_x = (d_all->pos_x - \
			floor(d_all->pos_x)) * d_all->grid_x;
	}
	else
	{
		d_all->step_x = 1;
		d_all->near_bound_x = (ceil(d_all->pos_x) - \
			d_all->pos_x) * d_all->grid_x;
	}
	if (d_all->direction_y < 0)
	{
		d_all->step_y = -1;
		d_all->near_bound_y = (d_all->pos_y - \
			floor(d_all->pos_y)) * d_all->grid_y;
	}
	else
	{
		d_all->step_y = 1;
		d_all->near_bound_y = (ceil(d_all->pos_y) - \
			d_all->pos_y) * d_all->grid_y;
	}
}

void	chose_direct(t_cub3d *cub, t_draw_all *d_all)
{
	d_all->direction_x = -(cub->hero->direction_x + \
		(cub->hero->plane_x * d_all->offset_from_center));
	d_all->direction_y = (cub->hero->direction_y) + \
		(cub->hero->plane_y * d_all->offset_from_center);
	d_all->grid_x = fabs(1 / d_all->direction_x);
	d_all->grid_y = fabs(1 / d_all->direction_y);
	some(cub, d_all);
}

int	go_vert(t_draw_all *d_all)
{
	d_all->near_bound_y += d_all->grid_y;
	d_all->pos_y += d_all->step_y;
	if (d_all->step_y < 0)
		return (SO);
	else
		return (NO);
}

int	go_hori(t_draw_all *d_all)
{
	d_all->near_bound_x += d_all->grid_x;
	d_all->pos_x += d_all->step_x;
	if (d_all->step_x < 0)
		return (WE);
	else
		return (EA);
}

int	found_hit(t_cub3d *cub, t_draw_all *d_all)
{
	int	play;

	play = 1;
	while (play)
	{
		if (d_all->near_bound_x < d_all->near_bound_y)
			d_all->dir = go_hori(d_all);
		else
			d_all->dir = go_vert(d_all);
		if (cub->map->map[(int)d_all->pos_y][(int)d_all->pos_x] > 0)
			play = 0;
	}
	if (d_all->dir == EA || d_all->dir == WE)
		d_all->dist_to_wall = (d_all->near_bound_x - d_all->grid_x);
	else
		d_all->dist_to_wall = (d_all->near_bound_y - d_all->grid_y);
	return ((int)(HEIGHT / d_all->dist_to_wall));
}

t_texture_map	*choose_texture(t_cub3d *cub, t_draw_all *d_all)
{
	t_texture_map	*texturs;

	texturs = cub->map->textures_names;
	while (texturs)
	{
		if (d_all->dir == NO && texturs->argv[0][0] == 'N')
			return (texturs);
		if (d_all->dir == WE && texturs->argv[0][0] == 'W')
			return (texturs);
		if (d_all->dir == EA && texturs->argv[0][0] == 'E')
			return (texturs);
		if (d_all->dir == SO && texturs->argv[0][0] == 'S')
			return (texturs);
		texturs = texturs->next;
	}
	return (NULL);
}

void	drawing_range(t_cub3d *cub, t_draw_all *d_all, int line_h)
{
	d_all->start = -line_h / 2 + HEIGHT / 2;
	if (d_all->start < 0)
		d_all->start = 0;
	d_all->end = line_h / 2 + HEIGHT / 2;
	if (d_all->end >= HEIGHT)
		d_all->end = HEIGHT - 1;
	if (d_all->dir == EA || d_all->dir == WE)
		d_all->dir_lock = cub->hero->y + \
			(d_all->dist_to_wall * d_all->direction_y);
	else
		d_all->dir_lock = cub->hero->x + \
			(d_all->dist_to_wall * d_all->direction_x);
	d_all->dir_lock -= floor(d_all->dir_lock);
	d_all->texture = choose_texture(cub, d_all);
}

void	found_text_p(t_point *point, t_draw_all *d_all)
{
	point->x = d_all->dir_lock * ((double)64);
	if (((d_all->dir == EA || d_all->dir == WE) \
		&& d_all->direction_x > 0) || ((d_all->dir == NO \
			|| d_all->dir == SO) && d_all->direction_y < 0))
		point->x = 64 - point->x - 1;
}

void	found_added(double *y_add, double *y_float, t_draw_all *d_all, int line_h)
{
	*y_add = 1.0 * 64 / line_h;
	*y_float = (d_all->start - HEIGHT / 2 + line_h / 2) * (*y_add);
}

t_color	unsigned_int_to_color(unsigned int sorce)
{
	t_color	color;

	color.t = (sorce >> 24) & 0xFF;
	color.red = (sorce >> 16) & 0xFF;
	color.green = (sorce >> 8) & 0xFF;
	color.blue = sorce & 0xFF;
	return (color);
}

int	get_pixel(int x, int y)
{
	return ((y * 256) + (x * 4));
}

int	texture_found(t_cub3d *cub, char f)
{
	t_texture_map	*textures;

	textures = cub->map->textures_names;
	while (textures)
	{
		if (f == textures->argv[0][0])
			return (textures->color);
		textures = textures->next;
	}
	return (textures->color);
}

void	draw_floor(t_cub3d *cub, t_draw_all *d_all)
{
	int	y;
	int	color;

	y = HEIGHT;
	color = texture_found(cub, 'F');
	while (y-- > d_all->end)
		put_pix(d_all->x, y, cub->env, color);
}

void	draw_up(t_cub3d *cub, t_draw_all *d_all)
{
	int	y;
	int	color;

	y = 0;
	color = texture_found(cub, 'C');
	while (y < d_all->start)
	{
		put_pix(d_all->x, y, cub->env, color);
		y++;
	}
}

void	draw_vert_line(t_cub3d *cub, t_draw_all *d_all, int line_h)
{
	double			y_addend;
	double			y_float;
	int				y_index;
	t_point			texture_p;

	found_text_p(&texture_p, d_all);
	found_added(&y_addend, &y_float, d_all, line_h);
	y_index = d_all->start - 1;
	if (d_all->end < 0)
		return ;
	draw_floor(cub, d_all);
	while (y_index++ < d_all->end)
	{
		texture_p.y = ((int)y_float) & (64 - 1);
		y_float += y_addend;
		if (d_all->texture->color == 1)
			put_pix_2(d_all->x, y_index, \
				cub->env, unsigned_int_to_color(*((unsigned int *) & \
					(d_all->texture->image_str[get_pixel(texture_p.x, \
						texture_p.y)]))));
		else
			put_pix(d_all->x, y_index, cub->env, d_all->texture->color);
	}
	draw_up(cub, d_all);
}

void	draw(t_cub3d *cub, t_draw_all *d_all)
{
	int		line_h;

	d_all->offset_from_center = (2 * d_all->x / ((float)WIDTH)) - 1;
	d_all->pos_x = cub->hero->x;
	d_all->pos_y = cub->hero->y;
	chose_direct(cub, d_all);
	line_h = found_hit(cub, d_all);
	drawing_range(cub, d_all, line_h);
	draw_vert_line(cub, d_all, line_h);
}


int	loop(t_cub3d *cub)
{
	t_draw_all	draw_all;

	(void)cub;
	mlx_clear_window(cub->env->window, cub->env->screen);
	ft_bzero(cub->env->image_str, WIDTH * HEIGHT * 4);
	draw_all.x = -1;
	while (draw_all.x++ < WIDTH)
		draw(cub, &draw_all);
	draw_minimap(cub);
	mlx_put_image_to_window(cub->env->window, \
		cub->env->screen, cub->env->image, 0, 0);
	return (0);
}
