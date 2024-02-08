#include "../../headers/cub3d.h"
#include "../../headers/errors.h"

#include "../../headers/mlx.h"

static void	emergency_clean(t_env *env, int stage)
{
	if (stage == 0)
	{
		mlx_destroy_display(env->window);
		free(env->window);
		free(env);
		emergency_exit_cub3d(MALLFAIL);
	}
	else if (stage == 1)
	{
		mlx_destroy_window(env->window, env->screen);
		mlx_destroy_display(env->window);
		free(env->window);
		free(env);
		emergency_exit_cub3d(MALLFAIL);
	}
}

t_env	*init_env(void)
{
	t_env	*env;
	int		bit_pet_line;
	int		line_size;
	int		endian;

	bit_pet_line = 32;
	line_size = WIDTH;
	endian = 1;
	env = malloc(sizeof(t_env));
	if (!env)
		emergency_exit_cub3d(MALLFAIL);
	env->window = NULL;
	env->screen= NULL;
	env->image = NULL;
	env->window = mlx_init();
	if (!env->window)
	{
		free(env);
		emergency_exit_cub3d(MALLFAIL);
	}
	env->screen = mlx_new_window(env->window, WIDTH, HEIGHT, NAME_WINDOW);
	if (!env->screen)
		emergency_clean(env, 0);
	env->image = mlx_new_image(env->window, WIDTH, HEIGHT);
	if (!env->image)
		emergency_clean(env, 1);
	env->image_str = mlx_get_data_addr(env->image, &bit_pet_line, &line_size, &endian);
	if (!env->image_str)
		emergency_clean(env, 1);
	return (env);
}

void	free_env(t_env **env)
{
	t_env	*clean;

	if (!env || !*env)
		return ;
	clean = *env;
	if (clean->window && clean->screen && clean->image)
		mlx_destroy_image(clean->window, clean->image);
	if (clean->window && clean->screen)
		mlx_destroy_window(clean->window, clean->screen);
	if (clean->window)
	{
		mlx_destroy_display(clean->window);
		free(clean->window);
	}
	free(clean);
	*env = NULL;
}
