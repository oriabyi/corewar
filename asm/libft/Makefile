# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akondaur <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/25 14:06:00 by akondaur          #+#    #+#              #
#    Updated: 2018/10/25 14:06:02 by akondaur         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
FILES = ft_lstiter.c ft_putendl.c ft_strequ.c ft_strnstr.c \
	ft_lstmap.c ft_putendl_fd.c ft_striter.c ft_strrchr.c ft_atoll.c \
	ft_atoi.c ft_lstnew.c ft_putnbr.c ft_striteri.c ft_strsplit.c \
	ft_bzero.c ft_memalloc.c ft_putnbr_fd.c ft_strjoin.c ft_strstr.c \
	ft_isalnum.c ft_memccpy.c ft_putstr.c ft_strlcat.c ft_strsub.c \
	ft_isalpha.c ft_memchr.c ft_putstr_fd.c ft_strlen.c ft_strtrim.c \
	ft_isascii.c ft_memcmp.c ft_strcat.c ft_strmap.c ft_tolower.c \
	ft_isdigit.c ft_memcpy.c ft_strchr.c ft_strmapi.c ft_toupper.c \
	ft_isprint.c ft_memdel.c ft_strclr.c ft_strncat.c ft_itoa.c \
	ft_memmove.c ft_strcmp.c ft_strncmp.c ft_lstadd.c ft_memset.c \
	ft_strcpy.c ft_strncpy.c ft_lstdel.c ft_putchar.c ft_strdel.c \
	ft_strnequ.c ft_lstdelone.c ft_putchar_fd.c ft_strdup.c ft_strnew.c \
	gnl.c otherypes.c str.c stuff.c uint.c getters.c int.c intspec.c \
	checkers.c ft_printf.c ft_itoa_base.c ft_nlen.c ft_putchar_utf8.c \
	ft_putcstr.c ft_putunbr.c ft_strllen.c ft_free_line.c ft_free_arr.c \
	ft_strsplit_spec.c ft_arrsize.c ft_arrjoin.c ft_arrjoin_del.c \
	ft_strjoin_del.c ft_free_arr.c ft_is_num.c

OBJECTS = $(FILES:.c=.o)
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	gcc -c $(FLAGS) $(FILES)
	ar rc $@ $(OBJECTS)
	ranlib $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all
