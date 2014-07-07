CC = gcc

NAME = corewar

LNAME = ft

DIR = lib$(LNAME)

HDR = $(DIR)/$(DIR).a

SRC = main.c       \
	  macro.c      \
	  battle.c     \
	  init_str.c   \
	  init_cycle.c \
	  conv.c       \
	  check_cmd.c  \
	  data_chp.c   \
	  str.c        \
	  tab1.c       \
	  tab2.c       \
	  tab3.c       \
	  tab4.c       \
	  ins_chp.c    \
	  instr.c      \
	  op.c         \
	  ll.c         \
	  neg_conv.c   \
	  dump.c       \
	  val.c        \
	  ar.c         \
	  check.c

OBJ = $(patsubst %.c,srcs/%.o,$(SRC))

LFLAGS = -L$(DIR) -l$(LNAME)

CFLAGS1 = -Wall -Werror -Wextra -Iincludes/ -I $(DIR)/includes/

OFLAGS = -O3 -g

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
