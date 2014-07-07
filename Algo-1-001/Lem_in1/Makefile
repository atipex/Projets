# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrebours <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/02/23 21:21:59 by mrebours            #+#    #+#              #
#    Updated: 2014/02/23 21:33:33 by mrebours           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

NAME = lem-in

LNAME = ft

DIR = lib$(LNAME)

HDR = $(DIR)/$(DIR).a

SRC =	fourmis.c	\
		error.c		\
		ft_tab.c	\
		solv_g.c	\
		solv.c		\
		path.c		\
		lab.c		\
		b_path.c	\
		build.c		\
		main.c

OBJ = $(patsubst %.c,srcs/%.o,$(SRC))

LFLAGS = -L$(DIR) -l$(LNAME)

CFLAGS1 = -Wall -Werror -Wextra -Iincludes/ -I $(DIR)/includes/

OFLAGS = -g

CFLAGS = $(CFLAGS1) $(OFLAGS)

all: $(HDR) $(NAME)

$(NAME): $(OBJ)
		@echo "creation de la fonction.."
		$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LFLAGS)
		@echo "\n"

$(HDR):
		@echo "creation de la library.."
		make -C $(DIR)
		@echo "\n"

clean:
		@echo "suppression des fichiers object..."
		@make -C $(DIR) clean
		rm -f $(OBJ) $(HDR)
		@echo "\n"

fclean: clean
		@echo "suppression de l'executable..."
		@make -C $(DIR) fclean
		rm -f $(NAME)
		@echo "\n"

re: fclean all

.PHONY: all clean fclean re
