/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariabyi <oleksandr32riabyi@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 14:42:07 by ariabyi           #+#    #+#             */
/*   Updated: 2017/11/27 17:15:33 by ariabyi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*list;
	t_list	*thenext;

	if (!alst || !*alst || !del)
		return ;
	list = *alst;
	while (list)
	{
		thenext = list->next;
		del(list->content, list->content_size);
		free(list);
		list = thenext;
	}
	*alst = NULL;
}
