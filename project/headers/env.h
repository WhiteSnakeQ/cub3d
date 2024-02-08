#ifndef ENV_H
# define ENV_H

# define NAME_WINDOW "CUB3D"

typedef struct s_env
{
	void	*window;
	void	*screen;
	void	*image;
	char	*image_str;
}			t_env;

t_env	*init_env(void);
void	free_env(t_env **env);

#endif
