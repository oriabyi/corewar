/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_getters2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akondaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 08:21:55 by akondaur          #+#    #+#             */
/*   Updated: 2018/12/25 08:21:57 by akondaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	ft_get_name2(t_asm *glob, int to_read, int fd)
{
	char *line_cont;
	char *prev;

	if (to_read)
		while (get_next_line(fd, &line_cont))
		{
			prev = glob->name;
			glob->name = ft_strjoin(glob->name, "\n");
			ft_free_line(&prev);
			ft_strcut(&line_cont, COMMENT_CHAR, ';');
			if ((glob->name = ft_strjoin_del(glob->name, line_cont))
			&& ft_strchr(glob->name, '\"') != ft_strrchr(glob->name, '\"'))
				break ;
		}
	ft_strcut(&(glob->name), COMMENT_CHAR, ';');
	line_cont = ft_strtrim(glob->name);
	if (ft_strchr(glob->name, '\"') == ft_strrchr(glob->name, '\"') ||
	line_cont[ft_strlen(line_cont) - 1] != '\"')
		ft_put_error(4, "hero's name");
	ft_free_line(&glob->name);
	glob->name = ft_strdup(line_cont + 1);
	glob->name[ft_strlen(glob->name) - 1] = '\0';
	ft_free_line(&line_cont);
}

static void	ft_get_comment2(t_asm *glob, int to_read, int fd)
{
	char *line_cont;
	char *prev;

	if (to_read)
		while (get_next_line(fd, &line_cont))
		{
			prev = glob->comment;
			glob->comment = ft_strjoin(glob->comment, "\n");
			ft_free_line(&prev);
			ft_strcut(&line_cont, COMMENT_CHAR, ';');
			if ((glob->comment = ft_strjoin_del(glob->comment, line_cont)) &&
			ft_strchr(glob->comment, '\"') != ft_strrchr(glob->comment, '\"'))
				break ;
		}
	ft_strcut(&(glob->name), COMMENT_CHAR, ';');
	line_cont = ft_strtrim(glob->comment);
	if (ft_strchr(glob->comment, '\"') == ft_strrchr(glob->comment, '\"') ||
	line_cont[ft_strlen(line_cont) - 1] != '\"')
		ft_put_error(4, "comment");
	ft_free_line(&glob->comment);
	glob->comment = ft_strdup(line_cont + 1);
	glob->comment[ft_strlen(glob->comment) - 1] = '\0';
	ft_free_line(&line_cont);
}

void		ft_get_name(t_asm *glob, char **arr, char *line, int fd)
{
	if (!glob->name && arr[1])
	{
		if (!ft_strchr(line, '\"'))
			ft_put_error(4, "hero's name");
		glob->name = ft_strdup(ft_strchr(line, '\"'));
		ft_get_name2(glob, ft_strchr(line, '\"') == ft_strrchr(line, '\"'), fd);
		(ft_strlen(glob->name) > PROG_NAME_LENGTH) ? ft_put_error(12,
		glob->name) : 0;
	}
	else
		ft_put_error(5, "hero's name");
}

void		ft_get_comment(t_asm *glob, char **arr, char *line, int fd)
{
	if (!glob->comment && arr[1])
	{
		if (!ft_strchr(line, '\"'))
			ft_put_error(4, "comment");
		glob->comment = ft_strdup(ft_strchr(line, '\"'));
		ft_get_comment2(glob, ft_strchr(line, '\"') == ft_strrchr(line, '\"'),
			fd);
		(ft_strlen(glob->comment) > COMMENT_LENGTH) ? ft_put_error(12,
		glob->comment) : 0;
	}
	else
		ft_put_error(5, "comment");
}
