/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariabyi <oleksandr32riabyi@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 14:39:45 by ariabyi           #+#    #+#             */
/*   Updated: 2017/11/27 17:16:32 by ariabyi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*newone;

	if (!alst || !*alst)
		return ;
	newone = *alst;
	*alst = NULL;
	del(newone->content, newone->content_size);
	free(newone);
	newone = NULL;
	return ;
}
