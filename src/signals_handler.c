/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 12:29:03 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/24 15:23:23 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	sig_suspend(void)
{
	canon(&g_cpy);
	signal(SIGTSTP, SIG_DFL);
	ioctl(STDWORK, TIOCSTI, "\x1A");
}

static void	handler(int sig)
{
	if (sig == SIGTSTP)
		sig_suspend();
	if (sig == SIGINT || sig == SIGABRT || sig == SIGSTOP ||
		sig == SIGKILL || sig == SIGQUIT)
	{
		canon(&g_cpy);
		exit(EXIT_SUCCESS);
	}
	else if (sig == SIGCONT)
	{
		no_canon(&g_cpy);
		signals_handler();
	}
}

void		signals_handler(void)
{
	signal(SIGINT, handler);
	signal(SIGTSTP, handler);
	signal(SIGCONT, handler);
	signal(SIGWINCH, handler);
	signal(SIGABRT, handler);
	signal(SIGSTOP, handler);
	signal(SIGKILL, handler);
	signal(SIGQUIT, handler);
}
