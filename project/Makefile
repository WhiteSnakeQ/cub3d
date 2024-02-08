SRC_FPR		= 	aditional_func.c \
				ft_printf.c \
				print_type.c \
				print_hex_address.c \
				put_decimal.c \
				put_hex_digit.c \
				put_str.c put_u_decimall.c \
				put_char.c \
				builder.c 
DIR_FPR		=	./scripts/printf/
OBJ_FPR		=	${addprefix ${DIR_FPR}, ${SRC_FPR:.c=.o}}

SRC_GNL		= 	get_next_line.c \
				get_next_line_utils.c
DIR_GNL		=	./scripts/get_next_line/
OBJ_GNL		=	${addprefix ${DIR_GNL}, ${SRC_GNL:.c=.o}}

SRC_STR		= 	string0.c \
				string1.c \
				string2.c \
				string3.c \
				string4.c \
				ft_convert_base.c \
				ft_convert_base2.c
DIR_STR		=	./scripts/string/
OBJ_STR		=	${addprefix ${DIR_STR}, ${SRC_STR:.c=.o}}

SRC_MAPP	= 	map_parse.c \
				check_valid_map.c \
				additional_map_fill_int.c \
				fill_map_texture.c \
				fill_map_int.c \
				argv_map.c \
				check_required_texture.c \
				final_check_map_parse.c
DIR_MAPP	=	./scripts/map_parsing/
OBJ_MAPP	=	${addprefix ${DIR_MAPP}, ${SRC_MAPP:.c=.o}}

SRC_INIT	= 	init_cub3d.c \
				init_map.c
DIR_INIT	=	./scripts/init_obj/
OBJ_INIT	=	${addprefix ${DIR_INIT}, ${SRC_INIT:.c=.o}}

SRC_ERROR	= 	emergency_exit.c\
				error.c
DIR_ERROR	=	./scripts/error_handling/
OBJ_ERROR	=	${addprefix ${DIR_ERROR}, ${SRC_ERROR:.c=.o}}

SRC_CUB3	= 	cub3d.c
DIR_CUB3	=	./scripts/cub3d/
OBJ_CUB3	=	${addprefix ${DIR_CUB3}, ${SRC_CUB3:.c=.o}}

SRC_CLEAN	= 	clean_cub3d.c \
				clean_map.c \
				t_map_argv.c
DIR_CLEAN	=	./scripts/cleaning/
OBJ_CLEAN	=	${addprefix ${DIR_CLEAN}, ${SRC_CLEAN:.c=.o}}

SRC_MINMAP	= 	operate.c
DIR_MINMAP	=	./scripts/minimap/
OBJ_MINMAP	=	${addprefix ${DIR_MINMAP}, ${SRC_MINMAP:.c=.o}}

SRC_ENV		= 	init_env.c
DIR_ENV		=	./scripts/env/
OBJ_ENV		=	${addprefix ${DIR_ENV}, ${SRC_ENV:.c=.o}}

SRC_SET		= 	settings.c
DIR_SET		=	./scripts/settings/
OBJ_SET		=	${addprefix ${DIR_SET}, ${SRC_SET:.c=.o}}

SRC_KEY		= 	key.c
DIR_KEY		=	./scripts/settings/key_assigment/
OBJ_KEY		=	${addprefix ${DIR_KEY}, ${SRC_KEY:.c=.o}}

SRC_LOOP	= 	loop.c \
				draw_minimap.c
DIR_LOOP	=	./scripts/loop_action/
OBJ_LOOP	=	${addprefix ${DIR_LOOP}, ${SRC_LOOP:.c=.o}}

SRC_HERO	= 	hero.c \
				action.c
DIR_HERO	=	./scripts/hero/
OBJ_HERO	=	${addprefix ${DIR_HERO}, ${SRC_HERO:.c=.o}}

ALLOBJ		=	${OBJ_CLEAN} ${OBJ_CUB3} ${OBJ_ERROR} ${OBJ_INIT} ${OBJ_MAPP} ${OBJ_STR} \
				${OBJ_GNL} ${OBJ_FPR} ${OBJ_MINMAP} ${OBJ_ENV} ${OBJ_SET} ${OBJ_KEY} \
				${OBJ_LOOP} ${OBJ_HERO}

NAME		=	cub3d

AR			=	ar rc

LIBR		=	ranlib

GCC			=	cc

CFLAGS		=	-Wall -Wextra -Werror

all:		${NAME}

.c.o:
			${GCC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${ALLOBJ}
			${GCC} ${CFLAGS} ${ALLOBJ} -o ${NAME}  ./scripts/minilibx/libmlx_Linux.a  -lXext -lX11 -lm -L./scripts/minilibx -lmlx

miniib:		
			@${MAKE} -C ./scripts/minilibx/

clean:
			@rm -f ${ALLOBJ}

fclean:		clean
			@rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re