#include "../../headers/map.h"
#include "../../headers/string_work.h"
#include "fcntl.h"

#include "../../headers/ft_printf.h"

static int	rgb_transform(char **rgb, int _return)
{
	char	*r;
	char	*g;
	char	*b;
	char	*tmp_color;
	char	*color;

	r = ft_convert_base(rgb[0], "0123456789", "0123456789abcdefg");
	g = ft_convert_base(rgb[1], "0123456789", "0123456789abcdefg");
	b = ft_convert_base(rgb[2], "0123456789", "0123456789abcdefg");
	if (!str_is_digit(r) || !str_is_digit(g) || !str_is_digit(b))
		return (free_string(&r), free_string(&g), free_string(&b), 0);
	if (ft_atoi(r) > 255 || ft_atoi(g) > 255 || ft_atoi(b) > 255)
		return (free_string(&r), free_string(&g), free_string(&b), 0);
	tmp_color = ft_strjoin(r, g);
	free_string(&tmp_color);
	color = ft_strjoin(tmp_color, b);
	tmp_color = ft_convert_base(color, "0123456789abcdefg", "01234567890");
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
		}
		textures = textures->next;
	}
	return (1);
}