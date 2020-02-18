/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_mode.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 15:37:17 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/18 15:42:16 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	no_canon(struct termios *cpy_cfg)
{
	struct termios	new_cfg;
	int				st_tc;

	st_tc = tcgetattr(STDWORK, cpy_cfg);
	ft_chk_sys_error(st_tc, E_TCGETATTR);
	new_cfg.c_lflag &= ~(ICANON | ECHO);
	st_tc = tcsetattr(STDWORK, TCSANOW, &new_cfg);
	ft_chk_sys_error(st_tc, E_TCSETATTR);
}

void	canon(struct termios *cpy_cfg)
{
	int	st_tc;

	st_tc = tcsetattr(STDWORK, TCSANOW, cpy_cfg);
	ft_chk_sys_error(st_tc, E_TCSETATTR);
}
