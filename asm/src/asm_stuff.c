/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_stuff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akondaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 14:43:25 by akondaur          #+#    #+#             */
/*   Updated: 2018/12/23 17:35:41 by akondaur         ###   ########.fr       */
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
	(err == 9) ? ft_printf("Error: value missed near %s\n", str) : 0;
	(err == 10) ? ft_printf("Error: unknown label %s\n", str) : 0;
	(err == 11) ? ft_printf("Error: wrong type in %s\n", str) : 0;
	(err == 12) ? ft_printf("Error: is this \"%s\" \nokay for you? "
			"Be simplier!\n", str) : 0;
	(err == 13) ? ft_printf("Error: yep, we handle it too(check parameter %s)"
			"\n", str) : 0;
	(err == 14) ? ft_printf("Error: you need full header, dear\n") : 0;
	(err == 15) ? ft_printf("Error: last \\n missed\n") : 0;
	(err == 16) ? ft_printf("Error: check registers number %s\n", str) : 0;
	(err == 17) ? ft_printf("Usage: %s <sourcefile.s>\n", str) : 0;
	exit(-1);
}

void	ft_strcut(char **line, char c1, char c2)
{
	if (!line || !*line)
		return ;
	(ft_strchr(*line, c1)) ? *ft_strchr(*line, c1) = '\0' : 0;
	(ft_strchr(*line, c2)) ? *ft_strchr(*line, c2) = '\0' : 0;
}
