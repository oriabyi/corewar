/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akondaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 17:37:13 by akondaur          #+#    #+#             */
/*   Updated: 2018/10/24 17:37:35 by akondaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *tmp;
	t_list *dup;

	if (!lst)
		return (NULL);
	dup = f(lst);
	if (!(tmp = ft_lstnew(dup->content, dup->content_size)))
		return (NULL);
	if (lst && lst->next)
		if (!(tmp->next = ft_lstmap(lst->next, f)))
		{
			free(tmp);
			return (NULL);
		}
	return (tmp);
}
