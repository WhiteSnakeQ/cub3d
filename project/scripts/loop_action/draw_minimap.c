#include "../../headers/cub3d.h"
#include "../../headers/loop.h"
#include "../../headers/mlx.h"
#include "../../headers/map_id.h"
#include "../../headers/errors.h"

static int	get_color(int x, int y, t_cub3d *cub)
{
	int	r_x;
	int	r_y;
	int	index;

	r_x = x / cub->minimap->pixel_multipl;
	r_y = (y - cub->minimap->start) / cub->minimap->pixel_multipl;
	if (r_y >= cub->map->rows || r_x >= cub->map->coll)
		emergency_exit_cub3d(ERRCOORD);
	if (r_y < 0 || r_x < 0)
		emergency_exit_cub3d(ERRCOORD);
	index = cub->map->map[r_y][r_x];
	if (index == HERO)
		return (HERO_MAP);
	else if (index == EMPTY)
		return (EMPTY_MAP);
	else if (index == FLOOR)
		return (FLOOR_MAP);
	else if (index == WALL)
		return (WALL_MAP);
	else
		emergency_exit_cub3d(UNRECTEXTURE);
	return (0);
}

void	put_pixel_map(char *img, int x, int y, int color)
{
	int	lim_y;
	int	lim_x;
	int	curr_x;

	lim_x = x + (DEFMULTP * 4);
	lim_y = y + (DEFMULTP * 4);
	while (y < lim_y)
	{
		if (y >= HEIGHT || y <= 0)
			break ;
		curr_x = x;
		while (curr_x <= lim_x)
		{
			if (curr_x >= WIDTH || x <= 0)
				break ;
			img[(curr_x + (y * WIDTH)) * 4] = (color) & 0xFF;
			img[((curr_x + (y * WIDTH)) * 4) + 1] = (color >> 8) & 0xFF;
			img[((curr_x + (y * WIDTH)) * 4) + 2] = (color >> 16) & 0xFF;
			img[((curr_x + (y * WIDTH)) * 4) + 3] = (color >> 24);
			curr_x++;
		}
		y++;
	}
}

void	draw_minimap(t_cub3d *cub)
{
	int	y;
	int	x;
	int	action_y;
	int	action_x;

	y = cub->minimap->start;
	action_y = (cub->map->rows * cub->minimap->pixel_multipl) + cub->minimap->start;
	action_x = cub->map->coll * cub->minimap->pixel_multipl;
	while (y < action_y)
	{
		x = 0;
		while (x < action_x)
		{
			put_pixel_map(cub->env->image_str, x, y, get_color(x, y, cub));
			x += 4;
		}
		y += 4;
	}
}
