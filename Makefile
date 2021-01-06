NAME		=	Cub3D

RM			=	rm -f

CFLAGS		=	-Wall -Wextra -Werror -lm -lbsd -lX11 -lXext

GCC			=	gcc

INCLUDEH	=	-I cub3d.h ./minilibx-linux/libmlx.a

SRCS		=	cub3d.c ft_raycast.c ft_player.c ft_drawing.c ft_keys.c ft_textures.c \
				ft_parsing.c ft_gnl.c ft_gnl_tools.c ft_map.c ft_params.c ft_tools.c \
				ft_parse_sprite.c ft_sprites.c ft_check.c ft_bitmap.c

OBJS		=	$(SRCS:.c=.o)

$(NAME)	:	$(OBJS)
			gcc -o $(NAME) $(OBJS) $(INCLUDEH) $(CFLAGS)

all		:	$(NAME)

clean	:
			$(RM) $(OBJS)

fclean	:	clean
			$(RM) $(NAME)
			$(RM) bitmap.bmp

re		:	fclean all


run		:	all
			./Cub3d map.cub

# %.o		:	%.c
# 			$(GCC) $(CFLAGS) $(INCLUDEH) -c $<  -o $(<:.c=.o)