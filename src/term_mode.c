/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_mode.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 15:37:17 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/18 17:11:56 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static int	wputchar(int c)
{
	write(STDWORK, &c, 1);
	return (c);
}

void	no_canon(struct termios *cpy_cfg)
{
	struct termios	new_cfg;
	int				st_tc;

	st_tc = tcgetattr(STDWORK, cpy_cfg);
	ft_chk_sys_error(st_tc, E_TCGETATTR);
	new_cfg = *cpy_cfg;
	new_cfg.c_lflag &= ~(ICANON | ECHO);
	new_cfg.c_cc[VMIN] = 0;
	new_cfg.c_cc[VTIME] = 1;
	st_tc = tcsetattr(STDWORK, TCSANOW, &new_cfg);
	ft_chk_sys_error(st_tc, E_TCSETATTR);
	tputs(tgetstr("ti", NULL), 1, wputchar);
	tputs(tgetstr("vi", NULL), 1, wputchar);
}

void	canon(struct termios *cpy_cfg)
{
	int	st_tc;

	st_tc = tcsetattr(STDWORK, TCSANOW, cpy_cfg);
	ft_chk_sys_error(st_tc, E_TCSETATTR);
	tputs(tgetstr("ve", NULL), 1, wputchar);
	tputs(tgetstr("te", NULL), 1, wputchar);
}
