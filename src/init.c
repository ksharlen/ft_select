/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 15:43:05 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/19 20:24:28 by ksharlen         ###   ########.fr       */
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
	sl_tgetent(init->vterm);
}

void	init_termcap(t_info_args *args)
{
	args->italics = sl_tgetstr("us");
	args->clear_win = sl_tgetstr("cl");
	args->wn.cols = sl_tgetnum("co");
	args->wn.rows = sl_tgetnum("li");
printf("cols: %zd	rows: %zd\n", args->wn.cols, args->wn.rows);
// EXIT();
}
