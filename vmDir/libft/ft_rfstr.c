/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rfstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariabyi <oleksandr32riabyi@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 12:59:13 by ariabyi           #+#    #+#             */
/*   Updated: 2018/03/18 13:00:54 by ariabyi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			free_string(char *string, char *string1)
{
	free(string);
	free(string1);
	return (1);
}

static void			zero_all(unsigned int *ti, unsigned int *i, char **ret)
{
	*ti = 0;
	*i = 0;
	*ret = NULL;
}

char				*ft_rfstr(char *what, char *where, char *w, int code)
{
	char			*ret;
	char			*t;
	char			*t2;
	unsigned int	i;
	unsigned int	ti;

	zero_all(&ti, &i, &ret);
	if (!what || !where || (!w && code == 2))
		return (NULL);
	if (!ft_strcmp(what, where))
		return (ft_strdup(w));
	while (where[i])
	{
		while (*what == where[i] && what++ && (int)(ti = !ti ? i : ti) >= 0)
			i++;
		if (++i == 0 || !*what)
		{
			t = ti != 1 ? ft_strsub(where, 0, ti) : NULL;
			t2 = ft_strsub(where, i - 1, ft_strlen(where));
			ret = (code == 1) ? ft_strjoin(t, t2) : ft_multjoin(3, t, w, t2);
			free_string(t, t2);
			return (ret);
		}
	}
	return (NULL);
}
