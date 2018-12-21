/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akondaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 06:24:05 by akondaur          #+#    #+#             */
/*   Updated: 2018/12/03 06:24:19 by akondaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t		ft_protect_strlen(char *str)
{
	int		i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

static t_list		*new_fd_list(size_t fd, t_list **newlist)
{
	t_list		*list;

	if (*newlist == NULL)
		*newlist = ft_lstnew("\0", fd);
	list = *newlist;
	while ((list)->content_size != fd)
	{
		if ((list)->next == NULL)
		{
			if ((list->next = ft_lstnew("\0", fd)) == NULL)
				return (NULL);
		}
		list = list->next;
	}
	return (list);
}

char				*ft_free_strjoin(char *s1, char const *s2)
{
	char	*str;
	int		a;
	int		b;

	a = ft_strlen(s1);
	b = ft_strlen(s2);
	if (!s1 || !s2)
		return (NULL);
	if (!(str = (char*)ft_strnew(a + b)))
		return (NULL);
	a = 0;
	b = 0;
	while (s1[a])
	{
		str[a] = s1[a];
		a++;
	}
	while (s2[b])
		str[a++] = s2[b++];
	str[a] = '\0';
	free(s1);
	return (str);
}

int					get_next_line(const int fd, char **line)
{
	int					r;
	char				*tmp;
	char				buff[BUFF_SIZE + 1];
	static t_list		*newlist = NULL;
	t_list				*thislist;

	IF_C(fd < 0 || fd >= OPEN_MAX || BUFF_SIZE < 1 || BUFF_SIZE >= 8384700 ||
	(r = read(fd, buff, 0)) < 0);
	thislist = new_fd_list((size_t)fd, &newlist);
	tmp = thislist->content;
	while ((!(ft_strchr(tmp, '\n'))) && (r = read(fd, buff, BUFF_SIZE)))
	{
		buff[r] = '\0';
		IF_C(!(tmp = ft_free_strjoin(tmp, buff)));
	}
	if (*tmp == '\0')
		return (0);
	*line = ft_strsub(tmp, 0, ft_protect_strlen(tmp));
	if (ft_strlen(tmp) == ft_protect_strlen(tmp))
		thislist->content = ft_strdup(tmp + ft_protect_strlen(tmp));
	else
		thislist->content = ft_strdup(tmp + ft_protect_strlen(tmp) + 1);
	free(tmp);
	return (1);
}
