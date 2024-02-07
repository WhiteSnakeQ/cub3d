#include "../../headers/cub3d.h"
#include "../../headers/errors.h"

#include "../../headers/mlx.h"

void	init_env(void *cub_void)
{
	t_cub3d	*cub = ((t_cub3d *)cub_void);
	cub->env = malloc(sizeof(t_env));
	if (!cub->env)
		emergency_exit_cub3d(MALLFAIL);
	cub->env->window = NULL;
	cub->env->screen= NULL;
	cub->env->window = mlx_init();
	if (!cub->env->window)
		emergency_exit_cub3d(MALLFAIL);
	ft_printf(2, "f");
	cub->env->screen = mlx_new_window(cub->env->window, WIDTH, HEIGHT, "cub3d");
	if (!cub->env->screen)
		emergency_exit_cub3d(MALLFAIL);
	ft_printf(2, "f");
}

void	free_env(t_env **env)
{
	t_env	*clean;

	if (!env || !*env)
		return ;
	clean = *env;
	if(clean->screen)
		mlx_destroy_window(clean->screen, clean->window);
	if (clean->window)
		mlx_destroy_display(clean->window);
	*env = NULL;
}
