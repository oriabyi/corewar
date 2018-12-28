/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlcreate_link.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akondaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 09:10:37 by akondaur          #+#    #+#             */
/*   Updated: 2018/10/27 09:10:38 by akondaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_node	*ft_dlcreate_link(t_node *last, t_node *header, char *link_name)
{
	t_node *link;

	link = (t_node *)malloc(sizeof(t_node));
	if (last)
	{
		link->l = last;
		link->r = last->r;
		(link->r)->l = link;
		(link->l)->r = link;
	}
	else
	{
		link->l = link;
		link->r = link;
	}
	link->h = header;
	link->u = header->u;
	link->d = header;
	(link->u)->d = link;
	(link->d)->u = link;
	header->size++;
	link->sign = (char *)malloc(sizeof(char) * (ft_strlen(link_name) + 1));
	ft_memcpy(link->sign, link_name, sizeof(char) * ft_strlen(link_name));
	return (link);
}
