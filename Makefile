NAME	= cub3D

RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror

GCC		= gcc

INCLUDEH	= -I minilibx

MLX_DIR		=	minilibx_opengl

SRCS	=	main.c ft_raycast.c	ft_init_struct.c ft_drawing.c 

OBJS	= $(SRCS:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJS)
	$(MAKE) -C minilibx_opengl
	gcc $(CFLAGS) -o $(NAME) $(OBJS) -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit


.PHONY:	clean fclean re bonus bench bclean

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

%.o: %.c
	$(GCC) $(CFLAGS) $(INCLUDEH) -c $<  -o $(<:.c=.o)