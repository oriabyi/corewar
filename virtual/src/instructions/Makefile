# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ariabyi <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/11 15:21:59 by ariabyi           #+#    #+#              #
#    Updated: 2018/11/30 10:17:54 by ariabyi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY:		all clean

INCDIRVIR	=	../../includes
CFLAGS =	#-Wall -Wextra -Werror -O2


SRC		=	$(SRCDIRVIR)execute_the_instruction.c 	\
			$(SRCDIRVIR)addition_instruct.c 		\
			$(SRCDIRVIR)aff_instruct.c 				\
			$(SRCDIRVIR)alive_instruct.c 			\
			$(SRCDIRVIR)and_instruct.c 				\
			$(SRCDIRVIR)fork_instruct.c 			\
			$(SRCDIRVIR)jump_if_carry_instruct.c 	\
			$(SRCDIRVIR)load_index_instruct.c 		\
			$(SRCDIRVIR)load_instruct.c 			\
			$(SRCDIRVIR)long_fork_instruct.c 		\
			$(SRCDIRVIR)long_load_index_instruct.c 	\
			$(SRCDIRVIR)long_load_instruct.c 		\
			$(SRCDIRVIR)or_instruct.c 				\
			$(SRCDIRVIR)store_index_instruct.c 		\
			$(SRCDIRVIR)store_instruct.c 			\
			$(SRCDIRVIR)substraction_instruct.c 	\
			$(SRCDIRVIR)xor_instruct.c

OBJFOLD =	obj/

HEADER	=	-I $(INCDIRVIR)

OBJ =		$(addprefix $(OBJFOLD),$(patsubst %.c, %.o, $(wildcard $(SRC))))

all:	$(OBJ)

$(OBJFOLD)%.o:	%.c
	@mkdir -p $(OBJFOLD)
	@gcc $(CFLAGS) $(HEADER) -c $< -o $@

clean:
	@rm -rf $(OBJFOLD)
	@echo "objects removed"

re: clean all
