CC = gcc

NAME = ft_select

LNAME = ft

DIR = lib$(LNAME)

HDR = $(DIR)/$(DIR).a

SRC = main.c				\
	  ft_is_key.c			\
	  ft_is_key_arrow.c	\
	  ft_list.c			\
	  ft_print.c			\
	  ft_signal.c			\
	  ft_term.c			\
	  ft_tools.c

OBJ = $(patsubst %.c,srcs/%.o,$(SRC))

LFLAGS = -L$(DIR) -l$(LNAME) -L/usr/lib -ltermcap

CFLAGS1 = -Wall -Werror -Wextra -Iincludes/ -I $(DIR)/includes/

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
