# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: deannapiedra <deannapiedra@student.42.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/15 16:25:44 by deannapiedr       #+#    #+#              #
#    Updated: 2020/06/15 16:46:16 by deannapiedr      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	cub3d

RM		=	rm -f

CFLAGS	= 	-Wall -Wextra -Werror

CC		=	gcc

HEADER	=	-I minilibx

SRCS	=	main.c raycast.c init_struct.c drawing.c

OBJ		=	$(SRCS:.c=.o)

all		:	$(NAME)

$(NAME)	:	$(OBJ)
			cd minilibx_og && $(MAKE)
			cp minilibx_og/libmlx.a $(NAME)
			ar -rcs $(NAME) $(OBJ)
			gcc $(FLAGS) -o $(NAME) $(OBJS) -L libft -lft -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit

.PHONY	:	clean fclean re

clean	:
			$(RM) $(OBJ)
			cd minilibx_og && $(MAKE) clean

fclean	:	clean
			$(RM) $(NAME)
			cd minilibx_og && $(MAKE) fclean

re		:	fclean all

%.o		:	%.c
			$(CC) $(FLAGS) $(HEADER) -c $<  -o $(<:.c=.o)
