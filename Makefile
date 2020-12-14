NAME		=	cub3D.a

RM			=	rm -f

CFLAGS		=	-Wall -Wextra -Werror

GCC			=	gcc

INCLUDEH	=	-I cub3d.h

MLX_DIR		=	minilibx-linux

SRCS		=	cub3d.c ft_raycast.c ft_player.c ft_drawing.c ft_keys.c ft_textures.c \
				ft_parsing.c ft_gnl.c ft_gnl_tools.c ft_map.c ft_params.c ft_tools.c \
				ft_parse_sprite.c ft_sprites.c ft_check.c ft_bitmap.c

OBJS		=	$(SRCS:.c=.o)

$(NAME)	:	$(OBJS)
				$(MAKE) -C minilibx-linux
				gcc $(CFLAGS) -o $(NAME) $(OBJS) -L $(MLX_DIR) -lm -lbsd -lx11 -lXext

#mac: -lmlx -framework OpenGL -framework AppKit
#mac $(MAKE) -C minilibx_og

all		:	$(NAME)

clean	:
			$(RM) $(OBJS)

fclean	:	clean
			$(RM) $(NAME)
			$(RM) bitmap.bmp

re		:	fclean all


run		:	all
			./cub3d.a map.cub

# %.o		:	%.c
# 			$(GCC) $(CFLAGS) $(INCLUDEH) -c $<  -o $(<:.c=.o)