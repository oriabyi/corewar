/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_stuff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akondaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 14:43:25 by akondaur          #+#    #+#             */
/*   Updated: 2018/12/22 14:43:27 by akondaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		ft_put_error(int err, char *str)
{
	(!err) ? ft_printf("Error: %s missed\n", str) : 0;
	(err == 1) ? ft_printf("Error: can't open file %s\n", str) : 0;
	(err == 2) ? ft_printf("Error: file %s has incorrect extention\n", str) : 0;
	(err == 3) ? ft_printf("Error: can't close file %s\n", str) : 0;
	(err == 4) ? ft_printf("Error: incorrect %s\n", str) : 0;
	(err == 5) ? ft_printf(
			"Error: you're straddling two worlds! Chose one %s\n", str) : 0;
	(err == 6) ? ft_printf("Error: label %s has forbidden char(s)\n", str) : 0;
	(err == 7) ? ft_printf("Error: unknown operation %s\n", str) : 0;
	(err == 8) ? ft_printf("Error: some arguments missed or extra near %s\n",
			str) : 0;
	(err == 10) ? ft_printf("Error: unknown label %s\n", str) : 0;
	(err == 11) ? ft_printf("Error: wrong type in %s\n", str) : 0;
	(err == 12) ? ft_printf("Error: is this \"%s\" \nokay for you? "
			"Be simplier!\n", str) : 0;
	(err == 13) ? ft_printf("Error: yep, we handle it too(check parameter %s)"
			"\n", str) : 0;
	(err == 14) ? ft_printf("Error: you need full header, dear\n") : 0;
	(err == 15) ? ft_printf("Error: last \\n missed\n") : 0;
	(err == 16) ? ft_printf("Error: check registers number %s\n", str) : 0;
	system("leaks asm");
	exit(-1);
}

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

char	*ft_joinarg(char **arr)
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
