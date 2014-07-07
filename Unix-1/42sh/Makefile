SRC		=	src/main.c			\
			src/init.c			\
			src/send_env.c		\
			src/send_path.c		\
			src/send_cd.c		\
			src/small_functs.c	\
			src/error.c		\
			src/free.c		\
			src/linked_lists.c	\
			src/send_command.c	\
			src/termcaps.c		\
			src/send_cmd_data.c	\
			src/history.c		\
			src/replace_history.c	\
			src/auto_completation.c	\
			src/aff.c		\
			src/aff_pglob.c		\
			src/str_to_linked_list.c\
			src/replace_env_var.c	\
			src/auto_complete.c	\
			src/termcaps_fct.c	\
			src/add_space.c		\
			src/parser.c		\
			src/check.c		\
			src/lexer.c		\
			src/tree.c		\
			src/redi_pipe.c		\
			src/create_tree.c	\
			src/exec_tree.c		\
			src/redi.c			\
			src/exec_type.c		\
			src/pipe.c			\
			src/ft_exec.c		\
			src/exe_cmd.c		\
			src/globing.c		\
			src/back_ground.c		\
			src/fct_exec.c		\
			src/ft_echo.c		\
			src/ft_env.c		\
			src/ft_exit.c		\
			src/ft_setenv.c		\
			src/ft_unsetenv.c	\
			src/ft_cd.c		\
			src/ft_history.c	\
			src/ft_set.c		\
			src/ft_unset.c		\
			src/ft_alias.c		\
			src/fct_builtin.c	\
			src/ft_unalias.c

SRC_LIB		=	libft/ft_putstr.c		\
			libft/ft_putchar.c		\
			libft/ft_strlen.c		\
			libft/ft_printf.c		\
			libft/flags.c			\
			libft/ft_getnbr.c		\
			libft/ft_put_nbr.c		\
			libft/ft_strcmp.c		\
			libft/get_next_line.c		\
			libft/ft_strdup.c		\
			libft/ft_strcat.c

SRC_LOADING	=	makefile_deco/loading.c

OBJ		=	$(SRC:.c=.o)
OBJ_LIB		=	$(SRC_LIB:.c=.o)
OBJ_LOADING	=	$(SRC_LOADING:.c=.o)

NAME		=	42sh
NAME_LIB	=	libft/libft.a
NAME_LOADING	=	makefile_deco/loading

GREEN		=	\033[1;32m
CYAN		=	\033[1;36m
WHITE		=	\033[0m
RED		=	\033[1;31m

CFLAGS		+=	-Wall -Wextra -Werror -I include/

all:		$(NAME_LIB) $(NAME)

$(NAME):	$(OBJ)
		@echo -e "$(RED)\n > COMPILATION .C EN COURS\n"
		@./makefile_deco/loading
		@echo -e "$(WHITE)"
		cc -o $(NAME) $(OBJ) -Wall -Wextra -Werror -lft -L. -lncurses
		@echo -e "$(GREEN)\n > COMPILATION .C TERMINEE"
		@echo -e "$(CYAN)"
		@cat makefile_deco/header
		@echo -e "$(WHITE)"
		@cat makefile_deco/using
		@echo -e "$(GREEN)"

$(NAME_LIB):	$(OBJ_LIB) $(OBJ_LOADING)
		cc -o $(NAME_LOADING) $(OBJ_LIB) $(OBJ_LOADING)
		@echo -e "$(RED)\n > COMPILATION LIB EN COURS\n"
		@./makefile_deco/loading
		@echo -e "$(WHITE)"
		ar rc $(NAME_LIB) $(OBJ_LIB)
		cp $(NAME_LIB) .
		ranlib $(NAME_LIB)
		@echo -e "$(GREEN)\n > COMPILATION LIB TERMINEE$(WHITE)"

clean:
		@echo -e "$(RED)\t->>> SUPPRESSION DES .o <<<-$(WHITE)"
		rm -f $(OBJ)
		rm -f $(OBJ_LIB)
		rm -f $(OBJ_LOADING)

fclean:		clean
		@echo -e "$(RED)\t->>> SUPPRESSION DU BIN + LIB <<<-$(WHITE)"
		rm -f $(NAME)
		rm -f $(NAME_LIB)
		rm -f $(NAME_LOADING)

re:		fclean all

.PHONY:	all clean fclean re
