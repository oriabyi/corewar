/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_getters1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akondaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 08:22:13 by akondaur          #+#    #+#             */
/*   Updated: 2018/12/25 08:22:16 by akondaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	ft_get_two_bits(t_asm *glob, char *arg, int mod)
{
	glob->commands[++(glob->cur)] = (ft_atoi(arg + mod) >> 8) & 255;
	glob->commands[++(glob->cur)] = (ft_atoi(arg + mod)) & 255;
}

void	ft_get_four_bits(t_asm *glob, char *arg)
{
	glob->commands[++(glob->cur)] = (ft_atoi(arg + 1) >> 24) & 255;
	glob->commands[++(glob->cur)] = (ft_atoi(arg + 1) >> 16) & 255;
	ft_get_two_bits(glob, arg, 1);
}

void	ft_get_data(char *file, t_asm **glob)
{
	int		fd;
	char	*line;

	if ((fd = open(file, O_RDONLY)) == -1)
		ft_put_error(1, file);
	*glob = ft_init_asm(file);
	while (get_next_line(fd, &line) > 0)
	{
		ft_add_op(line, *glob, fd);
		ft_free_line(&line);
	}
	ft_connect_labels(*glob);
	if (!(*glob)->comment || !(*glob)->name)
		ft_put_error(0, (!(*glob)->comment) ? "comment" : "name");
	(ft_check_last_n(fd)) ? 0 : ft_put_error(15, NULL);
	ft_print_header(file, (*glob));
	if (close(fd))
		ft_put_error(3, file);
}

void	ft_get_prosses(t_asm *glob, char **arr)
{
	int		i;
	int		j;

	if (!arr || !arr[0])
		return ;
	(glob->cur)++;
	if ((i = ft_is_label(arr[0])))
		ft_add_label(glob, arr);
	j = 0;
	if (glob->n_labels > -1 && (glob->labels)[glob->n_labels]->indx
		== glob->cur && !arr[1])
	{
		(glob->cur)--;
		return ;
	}
	while (g_op_tab[j].name && ft_strcmp(g_op_tab[j].name, arr[i]))
		j++;
	if (!(g_op_tab[j].name))
		ft_put_error(7, arr[i]);
	ft_add_prosses(arr, glob, i, &g_op_tab[j]);
	if (glob->cur >= CHAMP_MAX_SIZE)
		glob->commands = realloc(glob->commands, glob->cur + CHAMP_MAX_SIZE);
}

char	ft_get_type_n(char **arr, t_op *op)
{
	char	type;
	int		len;

	type = 0;
	len = 0;
	while (arr[len] && len < op->n_par)
	{
		type = type << 2;
		if (arr[len][0] == 'r')
			type += 1;
		else if (arr[len][0] == DIRECT_CHAR)
			type += 2;
		else
			type += 3;
		len++;
	}
	while (len++ < MAX_ARGS_NUMBER)
		type = type << 2;
	return (type);
}
