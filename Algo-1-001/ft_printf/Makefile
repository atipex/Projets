NAME = libftprintf.a
OBJDIR = ./
SRCDIR = ./srcs/
BINDIR = ./
FLAGS = -Wall -Wextra -Werror

SRCS	= cpy_str.c \
	  is_flag.c \
	  ft_char_isnum.c \
	  ft_getnbr.c \
	  ft_printf.c \
	  ft_push_args.c \
	  ft_push_flag.c \
	  ft_putallstr.c \
	  ft_putchar.c \
	  ft_putnbr.c \
	  ft_putstr.c \
	  ft_strlen.c \
	  nbr_tobase.c \
	  parser.c \
	  print_char_arg.c \
	  print_flags.c \
	  print_nbr_arg.c \
	  print_spaces.c \
	  print_spec.c \
	  put_flags.c \
	  put_precision.c \
	  put_specifier.c \
	  put_width.c

OBJS = $(SRCS:.c=.o)
CSRCS = $(addprefix $(SRCDIR), $(SRCS))
COBJS = $(addprefix $(OBJDIR), $(OBJS))
CEXEC = $(addprefix $(BINDIR), $(NAME))

all: $(NAME)

$(NAME): $(CSRCS) ./includes/
	@ gcc $(FLAGS) -I./includes/ -c $(CSRCS)
	@ ar rc $(NAME) $(COBJS)
	@ ranlib $(NAME)

clean:
	@ rm -rf $(COBJS)

fclean: clean
	@ rm -f $(NAME)

re: fclean all

.PHONY : clean fclean

