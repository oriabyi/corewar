/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_operate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akondaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 14:41:16 by akondaur          #+#    #+#             */
/*   Updated: 2018/12/22 14:41:19 by akondaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_asm	*ft_init_asm(char *file)
{
	t_asm *asb;

	asb = (t_asm *)malloc(sizeof(t_asm));
	asb->file = ft_strdup(file);
	asb->name = NULL;
	asb->comment = NULL;
	asb->commands = (char *)malloc(CHAMP_MAX_SIZE);
	asb->size = 0;
	asb->n_labels = -1;
	asb->n_mislabels = -1;
	asb->cur = -1;
	return (asb);
}

void	ft_connect_labels(t_asm *glob)
{
	int i;
	int j;
	int pos;
	int n;
	int size;

	i = -1;
	while (++i <= glob->n_mislabels && (j = -1))
		while (++j <= glob->n_labels)
			if (!ft_strcmp(glob->mislabels[i]->name, glob->labels[j]->name))
			{
				pos = glob->mislabels[i]->cur;
				n = glob->labels[j]->indx - glob->mislabels[i]->start_op;
				size = (glob->mislabels[i]->size) ? 2 : 4;
				while (size)
				{
					glob->commands[pos + size] = n & 255;
					(size)--;
					n = n >> 8;
				}
				break ;
			}
			else if (j == glob->n_labels)
				ft_put_error(10, glob->mislabels[i]->name);
}

int		ft_is_label(char *command)
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
