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

CC			=	gcc
NAME		=	corewar

INCDIRVIR	=	./virtual/includes/
SRCDIRVIR	=	./virtual/src/
SRCDIRINS   =   ./virtual/src/instructions

SRCVIR		=	$(SRCDIRVIR)clean_all.c					\
				$(SRCDIRVIR)control_work.c				\
				$(SRCDIRVIR)getters.c					\
				$(SRCDIRVIR)main.c						\
				$(SRCDIRVIR)math_help_for_gets.c		\
				$(SRCDIRVIR)parse.c						\
				$(SRCDIRVIR)treatment_arguments.c		\
				$(SRCDIRVIR)visual.c 					\
				$(SRCDIRVIR)execute_the_instruction.c 	\
				$(SRCDIRVIR)get_t_dirs.c				\
				$(SRCDIRVIR)instructions.c				\
				$(SRCDIRVIR)aff_instruct.c 				\
				$(SRCDIRVIR)alive_instruct.c 			\
				$(SRCDIRVIR)fork_instruct.c 			\
				$(SRCDIRVIR)jump_if_carry_instruct.c 	\
				$(SRCDIRVIR)load_index_instruct.c 		\
				$(SRCDIRVIR)load_instruct.c 			\
				$(SRCDIRVIR)long_fork_instruct.c 		\
				$(SRCDIRVIR)long_load_instruct.c 		\
				$(SRCDIRVIR)store_index_instruct.c 		\
				$(SRCDIRVIR)store_instruct.c 			\
				$(SRCDIRVIR)add_sub_instructions.c      \
				$(SRCDIRVIR)check_instruction_args.c	\
				$(SRCDIRVIR)getters_args.c              \
				$(SRCDIRVIR)print_map.c                 \
				$(SRCDIRVIR)logical_operations.c        \
				$(SRCDIRVIR)trash.c



CFLAGS	=	#-Wall -Wextra -Werror
IFLAGS	=	-lncurses -ltermcap
LIBINCL	=	-L. libft/libft.a
LIBDIR	=	./libft
HEADER	=	-I $(INCDIRVIR)
OBJFOLD =	./.obj/
OBJ		=	$(addprefix $(OBJFOLD), $(SRCVIR:.c=.o))


all:            $(NAME)

$(NAME): $(OBJ)
	$(CC) $(IFLAGS) $(CFLAGS) $(LIBINCL) -o $(NAME) $(OBJ)
	@echo "corewar: done"

$(OBJ): | $(OBJFOLD)

$(OBJFOLD):
	@mkdir -p $(OBJFOLD)$(SRCDIRVIR)

$(OBJFOLD)%.o: %.c
	$(CC) $(CFLAGS) $(HEADER) -o $@ -c $<

clean:
	@rm -rf $(OBJFOLD)
	@echo "objects removed"

fclean: clean
	@rm -f $(NAME)
	@echo "binary removed"

re: fclean all

.PHONY: all clean fclean re $(NAME)