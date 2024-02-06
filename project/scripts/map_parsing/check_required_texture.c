#include "../../headers/map.h"
#include "../../headers/string_work.h"

static int	check_texture(char *str, t_texture_map *textures)
{
	while (textures)
	{
		if (!ft_strcmp(str, textures->argv[0]))
			return(1);
		textures = textures->next;
	}
	return (0);
}

int	check_required_texture(t_texture_map *textures)
{
	if (!check_texture("NO", textures) || \
		!check_texture("SO", textures))
		return (0);
	if (!check_texture("WE", textures) || \
		!check_texture("EA", textures))
		return (0);
	if (!check_texture("F", textures) || \
		!check_texture("C", textures))
		return (0);
	return (1);
}