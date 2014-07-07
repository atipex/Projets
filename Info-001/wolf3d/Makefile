# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrebours <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/04/19 12:21:54 by mrebours            #+#    #+#              #
#    Updated: 2014/05/02 19:29:48 by mrebours           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= wolf3d

SRC	= main.c \
	  print_line.c \
	  events.c \
	  map.c \
	  get_next_line.c \
	  list_map.c \
	  list_func.c \
	  find_wall.c \
	  event_key.c \
	  event_walk.c \
	  free_structs.c \
	  move_head.c \
	  utils.c \
	  check.c

OBJ	= $(patsubst %.c,srcs/%.o,$(SRC))

FLAGX = -L/usr/X11/lib -lX11 -lXext -lmlx -lm

CFLAGS = -Wall -Wextra -Werror -Iincludes/

CC	= gcc

RM	= rm -f

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(FLAGX)
clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all
