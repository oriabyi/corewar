# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ariabyi <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/28 14:39:08 by ariabyi           #+#    #+#              #
#    Updated: 2018/12/28 19:37:18 by ariabyi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re mclean mfclean mre

NAME		:= corewar

SRC_PATH	:= src/
INST_PATH	:= $(SRC_PATH)instructions/
VIS_PATH	:= $(SRC_PATH)visualization/
INIT_PATH	:= $(SRC_PATH)initialization/
PARS_PATH	:= $(SRC_PATH)parsing/
WAR_PATH	:= $(SRC_PATH)war/
AUX_PATH	:= $(SRC_PATH)auxiliary/

INC_PATH	:= includes/
LIB_PATH	:= ./libft/
OBJ_PATH	:= .obj/

CC			:= clang
CFLAGS		:= -g -Wall -Werror -Wextra
IFLAGS		:= -I $(INC_PATH) -I $(LIB_PATH)
LFLAGS		:= -lncurses

HFILES		:=	corewar_header corewar_visualization op
OPERATIONS	:=	add_sub_instructions aff_instruct alive_instruct	\
				fork_instruct jump_if_carry_instruct load_instruct	\
				load_index_instruct	store_index_instruct			\
				store_instruct logical_operations

FILES		:=	dump main

VISUALIZER	:=	visual_draw_main_function visual_draw_memory_window	\
				visual_draw_menu visual_draw_score_window			\
				visual_event_handler visual_init visual_init_colors	\
				visual_init_time visual_input_field_functions		\
				visual_reset_event visual_set_memory_print_attr		\
				visual_start_end_functions

PARSE		:=	check_champ getters math_help_for_gets				\
				operations_with_champs parse treatment_arguments	\
				fill_sort_champ

INITIALIZ	:=	create_memory_space fill_memory_space				\
				init_instructions init_structures                   \
				desired_function

WAR			:=	carriages_move check_cycle_to_die getters_args		\
				execute_the_instruction get_list_arguments			\
				check_instruction_args war_loop squire

AUX			:=	check_correctness clean_all control_work help_war   \
				help_reg

LIB			:=	$(LIB_PATH)libft.a

HDRS := $(addprefix $(INC_PATH), $(addsuffix .h, $(HFILES)))
SRCS := $(addprefix $(SRC_PATH), $(addsuffix .c, $(FILES)))
SRCS += $(addprefix $(INST_PATH), $(addsuffix .c, $(OPERATIONS)))
SRCS += $(addprefix $(VIS_PATH), $(addsuffix .c, $(VISUALIZER)))
SRCS += $(addprefix $(INIT_PATH), $(addsuffix .c, $(INITIALIZ)))
SRCS += $(addprefix $(PARS_PATH), $(addsuffix .c, $(PARSE)))
SRCS += $(addprefix $(WAR_PATH), $(addsuffix .c, $(WAR)))
SRCS += $(addprefix $(AUX_PATH), $(addsuffix .c, $(AUX)))

OBJS := $(addprefix $(OBJ_PATH), $(SRCS:%.c=%.o))

SKIP	:= \033[A
COLOR	:=				
MESSAGE	:= $(COLOR)[$(NAME)]----->\033[0m

all: $(NAME)

$(NAME): $(LIB) $(OBJ_PATH) $(OBJS)
	@ $(CC) $(CFLAGS) $(IFLAGS) $(LFLAGS) $(OBJS) $(LIB) -o $(NAME)
	@ echo "$(MESSAGE)$(COLOR)[BUILD : DONE$(COLOR)]"
$(LIB):
	@ make -C $(LIB_PATH)

$(OBJ_PATH):
	@ mkdir -p $(OBJ_PATH)$(INST_PATH)
	@ mkdir -p $(OBJ_PATH)$(VIS_PATH)
	@ mkdir -p $(OBJ_PATH)$(INIT_PATH)
	@ mkdir -p $(OBJ_PATH)$(PARS_PATH)
	@ mkdir -p $(OBJ_PATH)$(WAR_PATH)
	@ mkdir -p $(OBJ_PATH)$(AUX_PATH)
$(OBJ_PATH)%.o: %.c $(HDRS)
	@echo "$(MESSAGE)$(COLOR)[COMPILE: $<$(SKIP)"
	@echo ""
	@ $(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@
	@echo ""
	@echo "$(SKIP)\033[A\033[2K$(SKIP)"

clean: mclean
	@ make clean -C $(LIB_PATH)

fclean: mfclean
	@ make fclean -C $(LIB_PATH)

re: fclean all

mclean:
	@ rm -f $(OBJS) $(DEPS)

mfclean:
	@ rm -f $(NAME)
	@ rm -rf $(OBJ_PATH)

mre: mfclean all
