/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 15:43:05 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/18 16:02:23 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	init_term(struct s_init *init)
{
	int	st_stdwork;

	init->vterm = getenv("TERM");
	if (!init->vterm)
		syserror(__FILE__, "TERM not found");
	st_stdwork = isatty(STDWORK);
	if (st_stdwork != 1)
		syserror(__FILE__, "fd doesn't referring to a terminal");
	init->tty_name = ttyname(STDWORK);
	if (!init->tty_name)
		syserror(__FILE__, "fd is not connected to a terminal");
}
