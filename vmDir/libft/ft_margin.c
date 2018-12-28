/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_margin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariabyi <oleksandr32riabyi@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 12:20:12 by ariabyi           #+#    #+#             */
/*   Updated: 2018/01/21 12:23:06 by ariabyi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_margin(char *pen, char *apple)
{
	char		*applepen;
	char		*temp_applepen;

	applepen = NULL;
	temp_applepen = ft_strjoin(applepen, pen);
	applepen = ft_strjoin(temp_applepen, apple);
	ft_strdel(&temp_applepen);
	ft_strdel(&pen);
	ft_strdel(&apple);
	return (applepen);
}
