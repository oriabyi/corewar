/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariabyi <oleksandr32riabyi@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 14:50:46 by ariabyi           #+#    #+#             */
/*   Updated: 2017/11/27 17:21:38 by ariabyi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*newlst;
	t_list	*temp;
	t_list	*newtmp;

	if (!lst || !f)
		return (NULL);
	temp = f(lst);
	if ((newlst = ft_lstnew(temp->content, temp->content_size)))
	{
		newtmp = newlst;
		lst = lst->next;
		while (lst)
		{
			temp = f(lst);
			if (!(newtmp->next = ft_lstnew(temp->content, temp->content_size)))
				return (NULL);
			newtmp = newtmp->next;
			lst = lst->next;
		}
	}
	return (newlst);
}
