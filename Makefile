# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: deannapiedra <deannapiedra@student.42.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/15 16:25:44 by deannapiedr       #+#    #+#              #
#    Updated: 2020/06/15 16:29:54 by deannapiedr      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	cub3d.a

RM		=	rm -f

CFLAGS	= 	-Wall -Wextra -Werror

CC		=	gcc

HEADER	=	-I cub3d.h

SRCS	=	main.c raycast.c init_struct.c drawing.c

OBJ		=	$(SRCS:.c=.o)

all		:	$(NAME)

$(NAME)	:	$(OBJ)
			cd Cub3d42 && $(MAKE)
			cp Cub3d42/cub3d.a $(NAME)
			ar -rcs $(NAME) $(OBJ)

.PHONY	:	clean fclean re

clean	:
			$(RM) $(OBJ)
			cd Cub3d42 && $(MAKE) clean

fclean	:	clean
			$(RM) $(NAME)
			cd Cub3d42 && $(MAKE) fclean

re		:	fclean all

%.o		:	%.c
			$(CC) $(FLAGS) $(HEADER) -c $<  -o $(<:.c=.o)