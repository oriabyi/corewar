/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_bool_arr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akondaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 12:21:01 by akondaur          #+#    #+#             */
/*   Updated: 2018/12/27 12:21:03 by akondaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static char	*ft_contain_op(char *str)
{
	int		i;
	char	*name;

	i = -1;
	name = 0;
	while (g_op_tab[++i].name != 0)
		if (ft_strstr(str, g_op_tab[i].name) == str)
			name = (ft_strlen(name) > ft_strlen(g_op_tab[i].name)) ? name :
				g_op_tab[i].name;
	return (name);
}

char		**ft_arrsplit(char **arr, char *std)
{
	char	*p;
	char	**new;

	if (!arr || ft_strlen(arr[0]) == ft_strlen(std))
		return (arr);
	new = (char **)malloc(sizeof(char *) * 2);
	new[0] = ft_strdup(std);
	new[1] = NULL;
	p = arr[0];
	arr[0] = ft_strsub(arr[0], ft_strlen(std),
		ft_strlen(arr[0]) - ft_strlen(std));
	ft_free_line(&p);
	arr = ft_arrjoin_del(new, arr);
	return (arr);
}

char		**ft_continue_split(char **arr)
{
	if (arr && arr[0] && ft_strcmp(arr[0], NAME_CMD_STRING)
	&& ft_strcmp(arr[0], COMMENT_CMD_STRING) && !ft_is_label(arr[0])
	&& ft_strcmp(arr[0], ft_contain_op(arr[0])))
	{
		if (ft_strstr(arr[0], NAME_CMD_STRING) == arr[0])
			arr = ft_arrsplit(arr, NAME_CMD_STRING);
		else if (ft_strstr(arr[0], COMMENT_CMD_STRING) == arr[0])
			arr = ft_arrsplit(arr, COMMENT_CMD_STRING);
		else if (ft_contain_op(arr[0]))
			arr = ft_arrsplit(arr, ft_contain_op(arr[0]));
	}
	return (arr);
}

int			ft_is_label(char *command)
{
	int i;

	if (ft_strlen(command) && ft_strchr(command, LABEL_CHAR) == command +
	ft_strlen(command) - 1)
	{
		i = (int)ft_strlen(command) - 1;
		while (--i)
			if (!ft_strchr(LABEL_CHARS, command[i]))
				ft_put_error(6, command);
		return (1);
	}
	return (0);
}

char		*ft_joinarg(char **arr)
{
	char	*res;
	char	*prev;
	int		i;

	i = -1;
	res = NULL;
	while (arr && arr[++i])
	{
		prev = res;
		res = ft_strjoin(res, arr[i]);
		ft_free_line(&prev);
	}
	return (res);
}
