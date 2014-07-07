NAME = ft_select

SOURCE = main.c \
		 ft_str.c\
		 ft_show.c

OBJ = $(SOURCE:.c=.o)

FLAGS = -g

LTEM = -L /usr/lib -ltermcap

CC = gcc

LIB = libft.a

LIBDIR = ./libft

all: $(NAME)

$(NAME): $(LIB) $(OBJ)
		@echo "creation de la fonction..."
		$(CC) $(FLAGS) -o $(NAME) $(OBJ) -L. -lft $(LTEM)
		@echo "\n"

$(OBJ):
		@echo "creation des fichiers object..."
		$(CC) $(FLAGS) -c $(SOURCE) -I$(LIBDIR)
		@echo "\n"

$(LIB):
		@echo "creation de la library..."
		@(cd $(LIBDIR); $(MAKE) re;mv $(LIB) ..)

clean:
		@echo "suppression des fichiers object..."
		@(cd $(LIBDIR); $(MAKE)  clean)
		/bin/rm -f $(OBJ)
		@echo "\n"

fclean: clean
		@echo "suppression de l'executable..."
		@(cd $(LIBDIR); make fclean)
		/bin/rm -f $(NAME)
		@echo "\n"

re: fclean all

.PHONY: all clean fclean re
