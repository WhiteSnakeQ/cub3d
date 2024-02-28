#include "../../headers/map.h"
#include "../../headers/string_work.h"
#include "../../headers/map_id.h"
#include "fcntl.h"

#include "../../headers/ft_printf.h"
#include "../../headers/mlx.h"

static int	rgb_transform(char **rgb, int _return)
{
	char	*r;
	char	*g;
	char	*b;
	char	*tmp_color;
	char	*color;

	if (!str_is_digit(rgb[0]) || !str_is_digit(rgb[1]) || !str_is_digit(rgb[2]))
		return (0);
	if (ft_atoi(rgb[0]) > 255 || ft_atoi(rgb[1]) > 255 || ft_atoi(rgb[2]) > 255)
		return (0);
	r = ft_convert_base(rgb[0], "0123456789", "0123456789abcdef");
	g = ft_convert_base(rgb[1], "0123456789", "0123456789abcdef");
	b = ft_convert_base(rgb[2], "0123456789", "0123456789abcdef");
	tmp_color = ft_strjoin(r, g);
	color = ft_strjoin(tmp_color, b);
	free_string(&tmp_color);
	tmp_color = ft_convert_base(color, "0123456789abcdef", "0123456789");
	_return = ft_atoi(tmp_color);
	free_string(&tmp_color);
	free_string(&color);
	return (free_string(&r), free_string(&g), free_string(&b), _return);
}

int	check_colors(t_texture_map *textures)
{
	char	**rgb;
	char	*argv;
	int		size;

	while (textures)
	{
		argv = textures->argv[1];
		if (is_digit(argv[0]))
		{
			size = ft_strlen(argv);
			if (size >= 12 || size <= 4)
				return (0);
			if (count_symb(argv, ',') != 2)
				return (0);
			rgb = ft_split(argv, ',');
			textures->color = rgb_transform(rgb, 0);
			free_strings(rgb);
			if (textures->color == 0)
				return (0);
		}
		textures = textures->next;
	}
	return (1);
}

int	check_textures_exist(t_texture_map *textures, t_env *env)
{
	char	*argv;
	int		fd;
	int		height;
	int		width;

	height = HEIGHT;
	width = WIDTH;
	while (textures)
	{
		argv = textures->argv[1];
		if (argv[0] == '.')
		{
			fd = open(textures->argv[1], O_RDONLY);
			if (fd == -1 || !strcmp_back(argv, ".xpm", 4))
				return (0);
			close(fd);
			textures->image = mlx_xpm_file_to_image(env->window, \
				textures->argv[1], &width, &height);
			textures->image_str = \
				mlx_get_data_addr(textures->image, &fd, &fd, &fd);
			textures->color = TEXTURE;
		}
		textures = textures->next;
	}
	return (1);
}

int	last_check_map(t_texture_map *textures)
{
	while (textures)
	{
		if (textures->color == 0)
			return (0);
		textures = textures->next;
	}
	return (1);
}
