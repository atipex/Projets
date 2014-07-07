
NAME	=		filler

CC		=	gcc

SRC		=		main.c				\
				ft_play.c			\
				ft_destroy.c		\
				ft_init_piece.c		\
				ft_init_board.c		\
				ft_init_player.c	\

CC = gcc

LNAME = ft

DIR = lib$(LNAME)

HDR = $(DIR)/$(DIR).a

OBJ = $(patsubst %.c,srcs/%.o,$(SRC))

LFLAGS = -L$(DIR) -l$(LNAME)

CFLAGS1 = -g -Wall -Werror -Wextra -Iincludes/ -I $(DIR)/includes/

OFLAGS = -O3 -g

CFLAGS = $(CFLAGS1) $(OFLAGS)

all: $(HDR) $(NAME)

$(NAME): $(OBJ)
		@echo "creation de la fonction.."
		$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LFLAGS)
		@echo "\n"

$(HDR):
		@echo "Making lib.."
		make -C $(DIR)
		@echo "\n"

clean:
		@echo "Del obj.."
		@make -C $(DIR) clean
		rm -f $(OBJ) $(HDR)
		@echo "\n"

fclean:		clean
		@echo "Del bin.."
		@make -C $(DIR) fclean
		rm -f $(NAME)
		@echo "\n"

re: fclean all

.PHONY: all clean fclean re

