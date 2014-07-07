# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrebours <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/04/21 17:16:34 by mrebours            #+#    #+#              #
#    Updated: 2014/04/27 04:18:31 by mrebours           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	gcc

NAME	=	fdf

LNAME	=	ft

DIR		=	lib$(LNAME)

HDR		=	$(DIR)/$(DIR).a

LFLAGS	=	-L$(DIR) -l$(LNAME)

SRC = main.c \
	  ft_data.c \
	  ft_hook.c \
	  ft_draw.c \
	  ft_pixel_put.c \
	  ft_vector.c \
	  ft_grid.c

CFLAGS	=	-Wall -Wextra -Werror -Iincludes/ -I $(DIR)/includes/ -O3 -g

FLAGX = -L/usr/X11/lib -lX11 -lXext -lmlx

OBJ		=	$(patsubst %.c,src/%.o,$(SRC))

all: $(HDR) $(NAME)

$(NAME):	$(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(FLAGX) $(LFLAGS)

$(HDR):
	make -C $(DIR)

clean:
	make -C $(DIR) clean
	rm -f $(OBJ) $(HDR)

fclean:		clean
	make -C $(DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
