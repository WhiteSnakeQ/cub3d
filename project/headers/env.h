#ifndef ENV_H
# define ENV_H

typedef struct s_env
{
	void	*window;
	void	*screen;
}			t_env;

void	init_env(void *cub_void);
void	free_env(t_env **env);

#endif