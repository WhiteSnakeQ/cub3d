#ifndef ERRORS_H
# define ERRORS_H

# include "ft_printf.h"

# define WRNBARG "Wrong number of agrument!\n"
# define MALLFAIL "Malloc alocation failed!\n"
# define INVFORM "Invalid map format should be \".cub\"!\n"
# define INVFILE "Cannot open file!\n"
# define INVMAP "Invalid map!\n"
# define NCLOSE "Map not closed!\n"
# define SAMETEXTURE "Textures repid!\n"
# define ENSFTEXTURE "Invalid number of textures!\n"
# define INVCOLOR "Invalid colors!\n"
# define UNEXTEXTURE "Texture path is invalid!\n"
# define UNRECTEXTURE "Unrecognized texture!\n"
# define ERRCOORD "Setting coordinat error!\n"

void	emergency_exit_map(char *message, void *argv);
int		emergency_exit_cub3d(char *message);
int		error_message(char *message);

#endif