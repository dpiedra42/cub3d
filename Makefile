NAME		=	cub3D.a

RM			=	rm -f

# CFLAGS		=	-Wall -Wextra -Werror

CFLAGS      = ""

GCC			=	gcc

INCLUDEH	=	-I minilibx

MLX_DIR		=	minilibx_og

SRCS		=	cub3d.c ft_raycast.c ft_player.c ft_drawing.c ft_keys.c ft_textures.c \
				ft_parsing.c ft_gnl.c ft_gnl_tools.c ft_map.c ft_params.c ft_tools.c \
				ft_parse_sprite.c ft_sprites.c

OBJS		=	$(SRCS:.c=.o)

all		:	$(NAME)

$(NAME)	:	$(OBJS)
				$(MAKE) -C minilibx_og
				gcc $(CFLAGS) -o $(NAME) $(OBJS) -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit

.PHONY	:	clean fclean re

clean	:
			$(RM) $(OBJS)

fclean	:	clean
			$(RM) $(NAME)

re		:	fclean all

%.o		:	%.c
			$(GCC) $(CFLAGS) $(INCLUDEH) -c $<  -o $(<:.c=.o)