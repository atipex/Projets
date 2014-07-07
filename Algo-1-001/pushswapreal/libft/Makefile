# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrebours <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/04/19 12:26:42 by mrebours            #+#    #+#              #
#    Updated: 2014/04/19 12:26:45 by mrebours           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

OBJ = ft_strlen.o ft_strdup.o ft_strcpy.o ft_strncpy.o ft_strcat.o \
	ft_strncat.o ft_memset.o ft_memset.o ft_bzero.o ft_memcpy.o \
	ft_memccpy.o ft_memmove.o ft_memchr.o ft_memcmp.o ft_strlcat.o \
	ft_strchr.o ft_strrchr.o ft_strstr.o ft_strnstr.o ft_strcmp.o \
	ft_strncmp.o ft_atoi.o ft_isalpha.o ft_isdigit.o ft_isalnum.o \
	ft_isascii.o ft_isprint.o ft_toupper.o ft_tolower.o ft_putchar.o \
	ft_putendl.o ft_putnbr.o ft_putstr.o ft_putchar_fd.o ft_putstr_fd.o \
	ft_putendl_fd.o ft_putnbr_fd.o ft_strtrim.o ft_strclr.o ft_memalloc.o \
	ft_memdel.o ft_strdel.o ft_strnew.o ft_strequ.o ft_strnequ.o ft_striter.o \
	ft_striteri.o ft_strmap.o ft_strmapi.o ft_strjoin.o ft_strsub.o ft_itoa.o \
	ft_strsplit.o get_next_line.o

GCCFLAGS = -Werror -Wall -Wextra -O3 -Iincludes

all: $(NAME)

$(NAME): ft_strlen.o ft_strdup.o ft_strcpy.o ft_strncpy.o ft_strcat.o \
	ft_strncat.o ft_memset.o ft_memset.o ft_bzero.o ft_memcpy.o \
	ft_memccpy.o ft_memmove.o ft_memchr.o ft_memcmp.o ft_strlcat.o\
	ft_strchr.o ft_strrchr.o ft_strstr.o ft_strnstr.o ft_strcmp.o \
	ft_strncmp.o ft_atoi.o ft_isalpha.o ft_isdigit.o ft_isalnum.o \
	ft_isascii.o ft_isprint.o ft_toupper.o ft_tolower.o ft_putchar.o\
	ft_putendl.o ft_putnbr.o ft_putstr.o ft_putchar_fd.o ft_putstr_fd.o \
	ft_putendl_fd.o ft_putnbr_fd.o ft_strtrim.o ft_strclr.o ft_memalloc.o \
	ft_memdel.o ft_strdel.o ft_strnew.o ft_strequ.o ft_strnequ.o ft_striter.o \
	ft_striteri.o ft_strmap.o ft_strmapi.o ft_strjoin.o ft_strsub.o ft_itoa.o \
	ft_strsplit.o get_next_line.o

	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

ft_memset.o:
	@gcc $(GCCFLAGS) -c srcs/ft_memset.c

ft_bzero.o:
	@gcc $(GCCFLAGS) -c srcs/ft_bzero.c

ft_memcpy.o:
	@gcc $(GCCFLAGS) -c srcs/ft_memcpy.c

ft_memccpy.o:
	@gcc $(GCCFLAGS) -c srcs/ft_memccpy.c

ft_memmove.o:
	@gcc $(GCCFLAGS) -c srcs/ft_memmove.c

ft_memchr.o:
	@gcc $(GCCFLAGS) -c srcs/ft_memchr.c

ft_memcmp.o:
	@gcc $(GCCFLAGS) -c srcs/ft_memcmp.c

ft_strlen.o:
	@gcc $(GCCFLAGS) -c srcs/ft_strlen.c

ft_strdup.o:
	@gcc $(GCCFLAGS) -c srcs/ft_strdup.c

ft_strcpy.o:
	@gcc $(GCCFLAGS) -c srcs/ft_strcpy.c

ft_strncpy.o:
	@gcc $(GCCFLAGS) -c srcs/ft_strncpy.c

ft_strcat.o:
	@gcc $(GCCFLAGS) -c srcs/ft_strcat.c

ft_strncat.o:
	@gcc $(GCCFLAGS) -c srcs/ft_strncat.c

ft_strlcat.o:
	@gcc $(GCCFLAGS) -c srcs/ft_strlcat.c

ft_strchr.o:
	@gcc $(GCCFLAGS) -c srcs/ft_strchr.c

ft_strrchr.o:
	@gcc $(GCCFLAGS) -c srcs/ft_strrchr.c

ft_strstr.o:
	@gcc $(GCCFLAGS) -c srcs/ft_strstr.c

ft_strnstr.o:
	@gcc $(GCCFLAGS) -c srcs/ft_strnstr.c

ft_strcmp.o:
	@gcc $(GCCFLAGS) -c srcs/ft_strcmp.c

ft_strncmp.o:
	@gcc $(GCCFLAGS) -c srcs/ft_strncmp.c

ft_atoi.o:
	@gcc $(GCCFLAGS) -c srcs/ft_atoi.c

ft_isalpha.o:
	@gcc $(GCCFLAGS) -c srcs/ft_isalpha.c

ft_isdigit.o:
	@gcc $(GCCFLAGS) -c srcs/ft_isdigit.c

ft_isalnum.o:
	@gcc $(GCCFLAGS) -c srcs/ft_isalnum.c

ft_isascii.o:
	@gcc $(GCCFLAGS) -c srcs/ft_isascii.c

ft_isprint.o:
	@gcc $(GCCFLAGS) -c srcs/ft_isprint.c

ft_toupper.o:
	@gcc $(GCCFLAGS) -c srcs/ft_toupper.c

ft_tolower.o:
	@gcc $(GCCFLAGS) -c srcs/ft_tolower.c

ft_putchar.o:
	@gcc $(GCCFLAGS) -c srcs/ft_putchar.c

ft_putendl.o:
	@gcc $(GCCFLAGS) -c srcs/ft_putendl.c

ft_putnbr.o:
	@gcc $(GCCFLAGS) -c srcs/ft_putnbr.c

ft_putstr.o:
	@gcc $(GCCFLAGS) -c srcs/ft_putstr.c

ft_putchar_fd.o:
	@gcc $(GCCFLAGS) -c srcs/ft_putchar_fd.c

ft_putstr_fd.o:
	@gcc $(GCCFLAGS) -c srcs/ft_putstr_fd.c

ft_putendl_fd.o:
	@gcc $(GCCFLAGS) -c srcs/ft_putendl_fd.c

ft_putnbr_fd.o:
	@gcc $(GCCFLAGS) -c srcs/ft_putnbr_fd.c

ft_strtrim.o:
	@gcc $(GCCFLAGS) -c srcs/ft_strtrim.c

ft_strclr.o:
	@gcc $(GCCFLAGS) -c srcs/ft_strclr.c

ft_memalloc.o:
	@gcc $(GCCFLAGS) -c srcs/ft_memalloc.c

ft_memdel.o:
	@gcc $(GCCFLAGS) -c srcs/ft_memdel.c

ft_strdel.o:
	@gcc $(GCCFLAGS) -c srcs/ft_strdel.c

ft_strnew.o:
	@gcc $(GCCFLAGS) -c srcs/ft_strnew.c

ft_strequ.o:
	@gcc $(GCCFLAGS) -c srcs/ft_strequ.c

ft_strnequ.o:
	@gcc $(GCCFLAGS) -c srcs/ft_strnequ.c

ft_striter.o:
	@gcc $(GCCFLAGS) -c srcs/ft_striter.c

ft_striteri.o:
	@gcc $(GCCFLAGS) -c srcs/ft_striteri.c

ft_strmap.o:
	@gcc $(GCCFLAGS) -c srcs/ft_strmap.c

ft_strmapi.o:
	@gcc $(GCCFLAGS) -c srcs/ft_strmapi.c

ft_strjoin.o:
	@gcc $(GCCFLAGS) -c srcs/ft_strjoin.c

ft_strsub.o:
	@gcc $(GCCFLAGS) -c srcs/ft_strsub.c

ft_itoa.o:
	@gcc $(GCCFLAGS) -c srcs/ft_itoa.c

ft_strsplit.o:
	@gcc $(GCCFLAGS) -c srcs/ft_strsplit.c

get_next_line.o:
	@gcc $(GCCFLAGS) -c srcs/get_next_line.c

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
