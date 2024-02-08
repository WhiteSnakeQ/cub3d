#include "../../../headers/settings.h"
#include "../../../headers/errors.h"

int	close_program(void *param)
{
	(void)param;

	clean_cub3d(0, NULL);
	exit(0);
}

int	mouse_move(int x, int y, t_cub3d *cub)
{
	(void)cub;
	ft_printf(2, "%d %d mouse_move\n", x, y);
	return (1);
}

int	mouse_down(int key, int x, int y, t_cub3d *cub)
{
	(void)cub;
	ft_printf(2, "key %d %d %d mouse_down\n", key, x, y);
	return (1);
}

int	mouse_up(int key, int x, int y, t_cub3d *cub)
{
	(void)cub;
	ft_printf(2, "key %d %d %d mouse_up\n", key, x, y);
	return (1);
}

int	modify_points(int key, void *param)
{
	(void)param;
	ft_printf(2, "%d butt\n", key);
	return (1);
}

void	key_setup(t_env *env)
{
	mlx_hook(env->screen, 2, 0, &modify_points, env);	
	mlx_hook(env->screen, 4, 0, &mouse_down, env);
	mlx_hook(env->screen, 5, 0, &mouse_up, env);
	mlx_hook(env->screen, 6, 0, &mouse_move, env);
	mlx_hook(env->screen, 17, 0, &close_program, NULL);
}