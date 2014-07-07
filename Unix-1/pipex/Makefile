
CC = gcc

NAME = pipex

SRC =		main.c					\
			ft_putendl_fd.c			\
			init_fill_obj.c			\
			ft_strjoin.c			\
			ft_strlen.c				\
			ft_strnew.c				\
			ft_strncmp.c			\
			ft_strsplit.c			\
			ft_strsub.c				\
			step_one.c				\
			creat_tab_f1.c			\
			err.c					\
			where_is_the_cat.c		\

OBJ = $(patsubst %.c,srcs/%.o,$(SRC))

CFLAGS = -Wall -Wextra -Werror -pedantic -Iincludes/ -O3

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
