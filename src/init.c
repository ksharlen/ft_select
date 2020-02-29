/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 15:43:05 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/29 14:19:54 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void			init_new_elem(t_info_args *args, const char *argv)
{
	struct s_arg	*new;

	new = (struct s_arg *)ft_memalloc(sizeof(struct s_arg));
	ft_chk_null_ptr(new, E_MALLOC);
	new->name = ft_strdup(argv);
	new->qt_sym = ft_strlen(argv);
	if (new->qt_sym > args->max_len_arg)
		args->max_len_arg = new->qt_sym;
	check_colors_file(new);
	if (args->begin == NULL)
	{
		args->begin = new;
		new->prev = NULL;
	}
	else
	{
		new->prev = args->end;
		args->end->next = new;
	}
	new->next = NULL;
	args->end = new;
}

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
	char	*clear;

	args->italics = sl_tgetstr("us");
	args->return_cursor = sl_tgetstr("ho");
	args->wn.cols = sl_tgetnum("co");
	args->wn.rows = sl_tgetnum("li");
	clear = sl_tgetstr("cl");
	sl_tputs(clear, 1, wputchar);
}

void	args_init(t_info_args *args)
{
	args->begin = NULL;
	args->end = NULL;
	args->max_len_arg = 0;
	args->num_cur_pos = 0;
	args->lde.name = NULL;
	args->lde.size_name = 0;
	args->size = 0;
	args->sdm = NULL;
	ft_bzero(args->s_buf.buf_search, sizeof(char) * S_SEARCH);
	args->s_buf.len_str = 0;
}
