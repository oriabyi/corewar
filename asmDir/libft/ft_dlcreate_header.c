/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlcreate_header.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akondaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 09:10:27 by akondaur          #+#    #+#             */
/*   Updated: 2018/10/27 09:10:29 by akondaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlcreate_header(t_node **root, char *head_name)
{
	t_node *header;

	header = (t_node *)malloc(sizeof(t_node));
	header->h = (*root);
	header->r = (*root);
	header->l = (*root)->l;
	(header->r)->l = header;
	(header->l)->r = header;
	header->u = header;
	header->d = header;
	header->size = 0;
	header->sign = (char *)malloc(sizeof(char) * (ft_strlen(head_name) + 1));
	ft_memcpy(header->sign, head_name, ft_strlen(head_name));
	if (atoi(head_name) > 9)
		header->sign[2] = '\0';
	else
		header->sign[1] = '\0';
}
