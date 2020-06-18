NAME		=	cub3D.a

RM			=	rm -f

CFLAGS		=	-Wall -Wextra -Werror

GCC			=	gcc

INCLUDEH	=	-I minilibx

MLX_DIR		=	minilibx_og

SRCS		=	main.c ft_raycast.c ft_init_struct.c ft_drawing.c

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