/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_work.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaranni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 18:57:07 by obaranni          #+#    #+#             */
/*   Updated: 2018/12/28 18:57:10 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar_header.h"

int				notification_message(t_corewar *core, int notific_code,
														char *notific_message)
{
	ft_putendl_fd(notific_message, STDERR_FILENO);
	clean_all(core);
	if (notific_code == PRINT_USAGE)
		free(notific_message);
	return (notific_code);
}
