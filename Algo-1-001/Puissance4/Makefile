# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrebours <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/02/23 21:21:59 by mrebours            #+#    #+#              #
#    Updated: 2014/03/07 21:05:56 by mrebours         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

NAME = puissance4

LNAME = ft

DIR = lib$(LNAME)

HDR = $(DIR)/$(DIR).a

SRC =	main.c						\
		start_check.c				\
		fill_obj.c					\
		welcome.c					\
		aff_tab.c					\
		ft_match.c					\
		free_tab.c					\
		check_ins_col.c				\
		real_player.c				\
		to_obj.c					\
		to_obj2.c					\
		win.c						\
		win2.c						\
		tab_cpy.c

OBJ = $(patsubst %.c,srcs/%.o,$(SRC))

LFLAGS = -L$(DIR) -l$(LNAME)

CFLAGS1 = -Wall -Werror -Wextra -Iincludes/ -I $(DIR)/includes/

OFLAGS =  -g

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
