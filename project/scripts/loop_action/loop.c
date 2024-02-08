#include "../../headers/cub3d.h"
#include "../../headers/loop.h"
#include "../../headers/mlx.h"
#include "../../headers/string_work.h"
#include "../../headers/map_id.h"

#include "unistd.h"
#include "math.h"
#include "../../headers/ft_printf.h"
#include "../../headers/errors.h"

void	put_pix(int x, int y, t_env *env, int color)
{
	env->image_str[(x + (y * WIDTH)) * 4] = (color) & 0xFF;
	env->image_str[((x + (y * WIDTH)) * 4) + 1] = (color >> 8) & 0xFF;
	env->image_str[((x + (y * WIDTH)) * 4) + 2] = (color >> 16) & 0xFF;
	env->image_str[((x + (y * WIDTH)) * 4) + 3] = (color >> 24);
}

float	abs_m(float i)
{
	if (i < 0)
		return (-i);
	return (i);
}

// static int	get_color(int x, int y, t_cub3d *cub)
// {
// 	int	index;

// 	if (y >= cub->map->rows || x >= cub->map->coll)
// 		emergency_exit_cub3d(ERRCOORD);
// 	if (y < 0 || x < 0)
// 		emergency_exit_cub3d(ERRCOORD);
// 	index = cub->map->map[y][x];
// 	if (index == HERO)
// 		return (HERO_MAP);
// 	else if (index == EMPTY)
// 		return (EMPTY_MAP);
// 	else if (index == FLOOR)
// 		return (FLOOR_MAP);
// 	else if (index == WALL)
// 		return (WALL_MAP);
// 	else
// 		emergency_exit_cub3d(UNRECTEXTURE);
// 	return (0);
// }

void	verLine(int x, int y_s, int y_e, int color, t_env *env)
{
	ft_printf(2, "y_s %dm y_e %d\n", y_s, y_e);
	while (y_s < y_e)
	{
		put_pix(x, y_s, env, color);
		y_s++;
	}
	ft_printf(2, "finish put\n");
}

void	draw(t_cub3d *cub)
{
	float	posY = (float)cub->hero->y;
	float	posX = (float)cub->hero->x;  //x and y start position

	for (int x = 0; x < WIDTH; x++) // Проходим по всем X
	{
		float fRayAngle = (cub->hero->direction - cub->hero->direction_deg/2.0f) + ((float)x / (float)WIDTH) * cub->hero->direction_deg; //29.476402

		float fStepSize = 0.1f;		  // Increment size for ray casting, decrease to increase										
		float fDistanceToWall = 0.0f;

		float fEyeX = sinf(fRayAngle); // -0.932787 eX
		float fEyeY = cosf(fRayAngle); // -0.360429 eY

		int bitwall = 0;
		while (bitwall != 1 && fDistanceToWall < cub->hero->distance_view)
		{
			fDistanceToWall += fStepSize;
			int nTestX = (int)(posX + fEyeX * fDistanceToWall);
			int nTestY = (int)(posY + fEyeY * fDistanceToWall);
			if (nTestX < 0 || nTestX >= cub->map->coll || nTestY < 0 || nTestY >= cub->map->rows)
			{
				bitwall = 1;			// Just set distance to maximum depth
				fDistanceToWall = cub->hero->distance_view;
			}
			else if (cub->map->map[nTestY][nTestX] == 1)
				bitwall = 1;
			int nCeiling = (float)(HEIGHT/2.0) - HEIGHT / ((float)fDistanceToWall); 
   			int nFloor = HEIGHT - nCeiling;

			for (int y = 0; y < HEIGHT; y++)
    		{
       			if (y <= nCeiling)
            		put_pix(x, y, cub->env, HERO_MAP);
        		else if(y > nCeiling && y <= nFloor)
            		put_pix(x, y, cub->env, WALL_MAP);
        		else
            		put_pix(x, y, cub->env, FLOOR_MAP);
    		}
		}
	}
}


int	loop(t_cub3d *cub)
{
	(void)cub;
	mlx_clear_window(cub->env->window, cub->env->screen);
	ft_bzero(cub->env->image_str, WIDTH * HEIGHT * 4);
	draw(cub);
	draw_minimap(cub);
	move_hero(0.1, NULL);
	mlx_put_image_to_window(cub->env->window, cub->env->screen, cub->env->image, 0, 0);
	return (0);
}
