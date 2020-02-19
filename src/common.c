/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 20:12:23 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/19 20:44:38 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

ssize_t		sl_read(int fd, void *buf, size_t count)
{
	ssize_t	nread;

	nread = read(fd, buf, count);
	if (nread == -1)
		syserror(NULL, "read error: nread = -1");
	return (nread);
}

void		get_win_size(struct s_win *wn)
{
	struct winsize	win;
	int				ret_ioctl;

	ret_ioctl = ioctl(STDWORK, TIOCGWINSZ, &win);
	if (ret_ioctl == -1)
		syserror(NULL, "failed to get window size");
	wn->cols = win.ws_col;
	wn->rows = win.ws_row;
}

void		screen_update(t_info_args *args, struct s_win *wn)
{
	P_UNUSED(args);
	P_UNUSED(wn);
}
