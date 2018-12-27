/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akondaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 14:54:14 by akondaur          #+#    #+#             */
/*   Updated: 2018/12/22 14:54:16 by akondaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "libft.h"
# include "get_next_line.h"
# include "op.h"

typedef struct			s_label
{
	char				*name;
	int					indx;
}						t_label;

typedef struct			s_mislabel
{
	char				*name;
	int					cur;
	int					start_op;
	int					size;
}						t_mislabel;

typedef struct			s_asm
{
	char				*file;
	char				*name;
	char				*comment;
	int					size;
	char				*commands;
	int					cur;
	int					start_op;
	int					n_labels;
	int					n_mislabels;
	t_label				**labels;
	t_mislabel			**mislabels;
}						t_asm;

void					ft_add_op(char *line, t_asm	*glob, int fd);
void					ft_add_label(t_asm *glob, char **arr);
void					ft_add_mislabel(t_asm *glob, char *label,
	t_op *op, int indir);
void					ft_add_data(t_asm *glob, char *arg, t_op *op);
void					ft_add_prosses(char **arr, t_asm *glob,
	int i, t_op *op);
void					ft_connect_labels(t_asm *glob);
void					ft_print_int(int fd, int n);
void					ft_print_sequence(int fd, char *str, int size);
void					ft_print_header(char *file, t_asm *glob);
void					ft_get_name(t_asm *glob, char **arr, char *line,
		int fd);
void					ft_get_comment(t_asm *glob, char **arr, char *line,
		int fd);
void					ft_get_data(char *file, t_asm **glob);
void					ft_get_two_bits(t_asm *glob, char *arg, int mod);
void					ft_get_four_bits(t_asm *glob, char *arg);
void					ft_get_prosses(t_asm *glob, char **arr);
char					ft_get_type_n(char **arr, t_op *op);
char					*ft_joinarg(char **arr);
int						ft_put_error(int err, char *str);
void					ft_strcut(char **line, char c1, char c2);
int						ft_is_label(char *command);
char					**ft_continue_split(char **arr);
int						ft_check_extention(char *file);
int						ft_check_types(char **args, t_op *op);
int						ft_check_num(char *str);
int						ft_check_last_n(int	fd);
int						ft_check_commas(char *args, int n_op);
t_asm					*ft_init_asm(char *file);
#endif
