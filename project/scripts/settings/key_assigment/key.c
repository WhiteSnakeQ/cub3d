#include "../../../headers/settings.h"
#include "../../../headers/errors.h"
#include "../../../headers/key.h"

int	close_program(void *param)
{
	(void)param;

	clean_cub3d(0, NULL);
	exit(0);
}

int	mouse_move(int x, int y, t_cub3d *cub)
{
	static float	oldx = 0;
	float			newx;

	if (oldx == 0)
	{
		oldx = x;
		return (0);
	}
	newx = oldx - x;
	rotate_hero(0, NULL, newx * 0.005);
	(void)cub;
	(void)y;
	oldx = x;
	return (0);
}

int	modify_points(int key, void *param)
{
	(void)param;
	if (key == ESC)
		close_program(NULL);
	if (key == W_BUTTON)
		move_hero(0.05, NULL);
	else if (key == S_BUTTON)
		move_hero(-0.05, NULL);
	else if (key == D_BUTTON || key == RA_BUTTON)
		rotate_hero(1, NULL, 0.04);
	else if (key == A_BUTTON || key == LA_BUTTON)
		rotate_hero(-1, NULL, 0.04);
	return (1);
}

void	key_setup(t_cub3d *cub)
{
	mlx_hook(cub->env->screen, 2, 0, &modify_points, cub);
	mlx_hook(cub->env->screen, 6, 0, &mouse_move, cub);
	mlx_hook(cub->env->screen, 17, 0, &close_program, NULL);
}