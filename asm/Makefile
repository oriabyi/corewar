# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akondaur <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/03 18:29:33 by akondaur          #+#    #+#              #
#    Updated: 2018/12/14 01:42:28 by akondaur         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = asm

# srcs, path and obj

SRC_N			=	asm.c \
                    asm_adders.c \
                    asm_checkers.c \
                    asm_getters1.c \
                    asm_getters2.c \
                    asm_print.c \
                    asm_stuff.c \
		    asm_bool_arr.c \
                    get_next_line.c

SRC_P 			= ./src/
OBJ 			= $(addprefix $(OBJ_P),$(SRC_N:.c=.o))
OBJ_P			= ./obj/
INC 			= $(addprefix -I, $(INC_P))
INC_P			= ./includes/
HEADER			= $(addprefix $(INC_P), asm.h)

# libft

LIB_P			= ./libft/
ADD_LIB			= $(addprefix $(LIB_P),libft.a)
INC_LIB			= -I ./libft
LNK_LIB			= -L ./libft -l ft

# compiler

CC 				= gcc
CC_FLAGS 		= -g -Wall -Wextra -Werror

all: obj $(ADD_LIB) $(NAME)

obj:
	mkdir -p $(OBJ_P)

$(OBJ_P)%.o:$(SRC_P)%.c $(HEADER)
	$(CC) $(CC_FLAGS) $(INC_LIB) -I $(INC_P) -o $@ -c $<

$(ADD_LIB):
	make -C $(LIB_P)

$(NAME): $(OBJ)
	$(CC) $(LNK_LIB) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ_P)
	make -C $(LIB_P) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(LIB_P) fclean

re: fclean all

.PHONY: all clean fclean re
