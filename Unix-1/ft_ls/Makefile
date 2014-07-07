CC = gcc

NAME = ft_ls

LNAME = ft

DIR = lib$(LNAME)

HDR = $(DIR)/$(DIR).a

SRC = ft_lstsort.c    \
	  ft_lst.c        \
	  ft_parse_file.c \
	  ft_parser.c     \
	  ft_printdir.c   \
	  ft_printfiles.c \
	  ft_readdir.c    \
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
