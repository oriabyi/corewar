/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariabyi <oleksandr32riabyi@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 16:39:33 by ariabyi           #+#    #+#             */
/*   Updated: 2018/04/01 16:39:35 by ariabyi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_realloc(char *str)
{
	char	*tmp;
	size_t	n;

	if (!str)
		return (NULL);
	n = ft_strlen(str);
	if (!(tmp = ft_strnew((n + BUFF_SIZE))))
		return (NULL);
	ft_memmove(tmp, str, n);
	ft_strdel(&str);
	return (tmp);
}

void	addfile(int fd, char *line, t_list **files)
{
	size_t	size;
	t_list	*tmp;

	if (*files)
	{
		tmp = *files;
		while (tmp->next && (int)tmp->content_size != fd)
			tmp = tmp->next;
		if ((int)tmp->content_size == fd)
			ft_strdel((char **)(&tmp->content));
		else
			ft_lstadd(files, (tmp = (t_list *)malloc(sizeof(t_list))));
	}
	else
	{
		if (!(*files = (t_list *)malloc(sizeof(t_list))))
			return ;
		tmp = *files;
		tmp->next = NULL;
	}
	tmp->content_size = fd;
	size = ft_strlen(line) + 1;
	tmp->content = ft_strsub(line, size, ft_strlen(line + size));
}

int		handle_files(t_list *files, int fd, int *f, char **line)
{
	t_list			*file;
	size_t			i;

	file = files;
	i = 0;
	*f = 0;
	if (files)
		while (file)
		{
			if ((int)file->content_size == fd)
			{
				i = ft_strlen(file->content);
				*f = (int)i;
				break ;
			}
			file = file->next;
		}
	if (!(*line = ft_strnew(BUFF_SIZE + i)))
		return (-1);
	if (i)
	{
		ft_memmove(line[0], file->content, i);
		ft_strdel((char **)(&file->content));
	}
	return (i);
}

void	ft_doit(int *f, long long *i)
{
	if (*f)
	{
		*f = 0;
		*i = 0;
	}
}

int		gnl(const int fd, char **line)
{
	long long		i;
	static t_list	*files;
	long long		ret;
	size_t			oldi;
	int				f;

	if (!line || fd < 0 || (i = handle_files(files, fd, &f, line)) == -1)
		return (-1);
	while (((ret = read(fd, &line[0][i], BUFF_SIZE)) > 0) || f)
	{
		oldi = i;
		ft_doit(&f, &i);
		while (line[0][i] != '\0' && ret != -1)
			if (line[0][i] == '\n')
			{
				line[0][i] = '\0';
				if ((size_t)i < ret + oldi)
					addfile(fd, *line, &files);
				return (1);
			}
			else if ((++i % (BUFF_SIZE + oldi)) == 0)
				*line = ft_realloc(*line);
	}
	ft_strdel((ret == -1) ? line : NULL);
	return ((i > 0 && ret != -1) ? 1 : ret);
}
