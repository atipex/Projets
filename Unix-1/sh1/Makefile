
CC		=	gcc

NAME	=	ft_minishell1

LNAME	=	ft

DIR		=	lib$(LNAME)

HDR		=	$(DIR)/$(DIR).a

SRC		=	main.c				\
			init_fill_obj.c		\
			prompt.c			\
			test_param.c		\
			path.c				\
			ext_com.c			\
			setenv.c			\
			print_env.c			\
			built_in.c			\
			unsetenv.c			\
			cd.c				\
			search_obj.c		\
			cd_2.c				\
			ctrl.c				\
			env.c				\
			chain_to_array.c	\
			exit.c				\
			env_misc.c			\

OBJ		=	$(patsubst %.c,srcs/%.o,$(SRC))

LFLAGS	=	-L$(DIR) -l$(LNAME)

CFLAGS	=	-Wall -Wextra -Werror -pedantic -Iincludes/ -I $(DIR)/includes/ -O3

all:	$(HDR) $(NAME)

$(NAME):	$(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LFLAGS)

$(HDR):
	make -C $(DIR)

clean:
	make -C $(DIR) clean
	rm -f $(OBJ) $(HDR)

fclean:		clean
	make -C $(DIR) fclean
	rm -f $(NAME)

re:			fclean all

.PHONY: all clean fclean re
