# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ariabyi <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/14 11:21:10 by ariabyi           #+#    #+#              #
#    Updated: 2018/12/29 11:41:13 by ariabyi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			:=	clang

NAME		:=	libft.a

CFLAGS		:=	-Wall -Wextra -Werror
SRC_PATH	:=	./src/
HEADER		:=	libft.h
OBJ_PATH	:= .obj/

FILES		:=		ft_atoi					\
					ft_bzero				\
					ft_isalnum				\
					ft_isalpha				\
					ft_isascii				\
					ft_isdigit				\
        			ft_isprint				\
        			ft_itoa					\
        			ft_lstadd				\
        			ft_lstdel				\
        			ft_lstdelone			\
        			ft_lstiter				\
        			ft_lstmap				\
        			ft_lstnew				\
        			ft_memalloc				\
        			ft_memccpy				\
        			ft_memchr				\
        			ft_memcmp				\
        			ft_memcpy				\
        			ft_memdel				\
        			ft_memmove				\
        			ft_memset				\
        			ft_putchar				\
        			ft_putchar_fd			\
        			ft_putendl				\
        			ft_putendl_fd			\
        			ft_putnbr				\
        			ft_putnbr_fd			\
        			ft_putstr				\
        			ft_putstr_fd			\
        			ft_strcat				\
        			ft_strchr				\
        			ft_strclr				\
        			ft_strcmp				\
        			ft_strcpy				\
        			ft_strdel				\
        			ft_strdup				\
        			ft_strequ				\
        			ft_striter				\
        			ft_striteri				\
        			ft_strjoin				\
        			ft_strlcat				\
        			ft_strlen				\
        			ft_strmap				\
        			ft_strmapi				\
        			ft_strncat				\
        			ft_strncmp				\
        			ft_strncpy				\
        			ft_strnequ				\
        			ft_strnew				\
        			ft_strnstr				\
        			ft_strrchr				\
        			ft_strsplit				\
        			ft_strstr				\
        			ft_strsub				\
        			ft_strtrim				\
        			ft_tolower				\
        			ft_toupper				\
        			ft_strrev				\
        			ft_numodgt				\
        			ft_numows				\
        			ft_printbits			\
        			ft_printhex				\
        			ft_strpos				\
        			ft_swap					\
        			ft_wcase				\
        			ft_strcapitalize		\
        			ft_sqrt					\
        			ft_margin				\
        			ft_pwrbase				\
        			ft_csymb				\
        			ft_multjoin				\
        			ft_mstrcmp				\
        			ft_strprint				\
        			ft_rfstr				\
        			gnl						\
        			ft_split_wsps			\
					ft_iswsps				\
					ft_pmult_fd				\
					ft_setnum				\
					ft_check_iarr			\
					ft_are_nums				\
					free_str_return_int		\
					ft_multjoinfr			\
					lgnl					\
					ft_ahtoi				\
					raise_to_power			\
					get_num_in_hex			\
					get_hex_by_int_byte		\
					int_to_char_hex			\
					free_char_matrix		\
					append_char				\
					ft_multcat				\
					count_chars				\
					check_got_num			\
					are_nums
	
SRCS	:= $(addprefix $(SRC_PATH), $(addsuffix .c, $(FILES)))
OBJ		:= $(addprefix $(OBJ_PATH), $(SRCS:%.c=%.o))

SKIP	:= \033[A
COLOR	:=				
MESSAGE	:= $(COLOR)[$(NAME)]----->\033[0m

all: $(NAME)

$(NAME): $(OBJ)
	@ ar rc $(NAME) $(OBJ)
	@ ranlib $(NAME)
	@echo "$(MESSAGE)$(COLOR)[BUILD : DONE$(COLOR)]"

$(OBJ): | $(OBJ_PATH)

$(OBJ_PATH):
	@ mkdir -p $(OBJ_PATH)$(SRC_PATH)

$(OBJ_PATH)%.o: %.c
	@echo "$(MESSAGE)$(COLOR)[COMPILE: $<$(SKIP)"
	@echo ""
	@ $(CC) $(CFLAGS) -o $@ -c $<
	@echo ""
	@echo "$(SKIP)\033[A\033[2K$(SKIP)"

clean:
	@ rm -f $(OBJ)

fclean: clean
	@ rm -f $(NAME)
	@ rm -rf $(OBJ_PATH)

re: fclean all

.PHONY: all clean fclean re
