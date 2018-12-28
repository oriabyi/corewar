/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_checkers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akondaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 14:38:48 by akondaur          #+#    #+#             */
/*   Updated: 2018/12/22 14:38:51 by akondaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		ft_check_extention(char *file)
{
	if (ft_strstr(file, ".s") && !ft_strncmp(file + ft_strlen(file) - 2, ".s",
		2))
		return (1);
	return (0);
}

int		ft_check_types(char **args, t_op *op)
{
	int i;
	int type;

	i = 0;
	while (args && args[i] && i < op->n_par)
	{
		if (args[i][0] == 'r')
			type = T_REG;
		else if (args[i][0] == DIRECT_CHAR)
			type = T_DIR;
		else
			type = T_IND;
		((ft_strlen(args[i]) > 1 && type != T_IND) || (ft_strlen(args[i])
			> 0 && type == T_IND)) ? 0 : ft_put_error(9, args[i]);
		if ((op->type_arg[i] & type) != type)
			return (0);
		else
			i++;
	}
	return (1);
}

int		ft_check_num(char *str)
{
	int j;

	j = -1;
	while (++j < (int)ft_strlen(str))
		if (!ft_isdigit(str[j]) && !((str[j] == '-'
			|| str[j] == '+') && !j))
			return (0);
	return (1);
}

int		ft_check_last_n(int fd)
{
	char b;

	lseek(fd, -1, SEEK_END);
	if (read(fd, &b, 1) > 0)
		return (b == '\n');
	ft_putnbr(fd);
	return (0);
}

int		ft_check_commas(char *args, int n_op)
{
	int i;

	i = -1;
	while (++i < n_op - 1)
	{
		while (*args)
			if (*args == SEPARATOR_CHAR && *(args + 1) != SEPARATOR_CHAR)
				break ;
			else if (*args == SEPARATOR_CHAR && *(args + 1) == SEPARATOR_CHAR)
				return (0);
			else
				args++;
		args++;
	}
	return (i == n_op - 1 && !ft_strchr(args, SEPARATOR_CHAR));
}
