/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 16:03:36 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/18 16:07:38 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	sl_tgetent(char *vterm)
{
	int	ok;

	ok = tgetent(vterm, NULL);
	if (ok != 1)
		syserror(__FILE__, "termcap for current terminal not found");
}

char	*sl_tgetstr(char *cb)
{
	char	*str;

	str = NULL;
	if (cb)
	{
		str = tgetstr(cb, NULL);
		ft_chk_null_ptr(str, E_TGETSTR);
	}
	else
		syserror(__FILE__, "input_tgetstr: empty cb");
	return (str);
}

char	*sl_tgoto(char *cb, int one, int two)
{
	char	*str;

	str = NULL;
	if (cb)
	{
		str = tgoto(cb, one, two);
		ft_chk_null_ptr(str, E_TGOTO);
	}
	else
		syserror(__FILE__, "input_tgoto: empty cb");
	return (str);
}

void	sl_tputs(const char *str, int affcnt, int (*putc)(int))
{
	int	ret_tputs;

	if (str)
	{
		ret_tputs = tputs(str, affcnt, putc);
		ft_chk_sys_error(ret_tputs, E_TPUTS);
	}
	else
		syserror(__FILE__, "input_tputs: empty str");
}

int		sl_tgetnum(char *str)
{
	int		val;

	val = -1;
	if (str)
	{
		val = tgetnum(str);
		if (val == -1)
			syserror(__FILE__, "input_tgetnum: val = -1");
	}
	else
		syserror(__FILE__, "input_tgetnum: empty str");
	return (val);
}
