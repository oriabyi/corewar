/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_champ.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariabyi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 17:57:37 by ariabyi           #+#    #+#             */
/*   Updated: 2018/12/28 17:57:38 by ariabyi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar_header.h"

int					check_champ_extension(char *champ_file_name)
{
	if (ft_strcmp(champ_file_name + ft_strlen(champ_file_name) - 3, "cor") == 0)
		return (0);
	return (1);
}

int					check_champ_type(char *champ_file_name)
{
	struct stat		sb;

	if (lstat(champ_file_name, &sb) == -1)
		return (FILE_DOESNT_EXIST);
	if (S_ISREG(sb.st_mode))
		return (FILE_IS_REG);
	else if (S_ISFIFO(sb.st_mode))
		return (FILE_IS_PIPE);
	else if (S_ISCHR(sb.st_mode))
		return (FILE_IS_SPEC_CHAR);
	else if (S_ISDIR(sb.st_mode))
		return (FILE_IS_DIR);
	else if (S_ISSOCK(sb.st_mode))
		return (FILE_IS_SOCKET);
	else if (S_ISBLK(sb.st_mode))
		return (FILE_IS_BLOCK);
	else
		return (WRONG_FILE_TYPE);
}

int					check_champ_file(char *champfilename)
{
	int				check_num;

	if (access(champfilename, F_OK) == -1)
		return (FILE_DOESNT_EXIST);
	if (access(champfilename, R_OK) == -1)
		return (NO_RIGHT_FOR_READ);
	if ((check_num = check_champ_type(champfilename)) != FILE_IS_REG)
		return (check_num);
	if (check_champ_extension(champfilename) == 1)
		return (BAD_CHAMP_EXTENSION);
	return (0);
}

int					check_champ_info(t_champ *champ)
{
	size_t			len;

	if ((len = ft_strlen(champ->name)) == 0 || len > PROG_NAME_LENGTH)
		return (BAD_NAME_LENGTH);
	else if (champ->size > CHAMP_MAX_SIZE || champ->size == 0)
		return (BAD_CHAMP_SIZE);
	else if ((len = ft_strlen(champ->comment)) == 0 || len > COMMENT_LENGTH)
		return (BAD_COMMENT_LENGTH);
	return (0);
}
