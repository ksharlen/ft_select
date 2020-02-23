/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 20:13:13 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/21 17:09:38 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int			wputchar(int c)
{
	write(STDWORK, &c, 1);
	return (c);
}

static size_t	get_qt_selected(struct s_arg *args)
{
	size_t	qt_selected;

	qt_selected = 0;
	while (args)
	{
		if (args->status & SELECT)
			++qt_selected;
		args = args->next;
	}
	return (qt_selected);
}

void	print_selected_args(t_info_args *args)
{
	struct s_arg	*current;
	size_t			qt_selected;

	if (args->begin)
	{
		qt_selected = get_qt_selected(args->begin);
		current = args->begin;
		while (current)
		{
			if (current->status & SELECT)
			{
				if (args->status & REV_MODE)
					revers_word((char *)current->name);
				--qt_selected;
				if (qt_selected)
					ft_printf("%s ", current->name);
				else
					ft_printf("%s\n", current->name);
			}
			current = current->next;
		}
	}
}

//TODO: need fix gut when resize window
void	print_args(t_info_args *args)
{
	struct s_arg	*current;
	size_t			sym_qt_in_line;

	if (args->size)
	{
		sym_qt_in_line = 0;
		sl_tputs(args->return_cursor, 1, wputchar);
		ft_print_nsym(STDWORK, ' ', (args->wn.cols) * (args->wn.rows));
		sl_tputs(args->return_cursor, 1, wputchar);
		current = args->begin;
		while (current)
		{
			if (args->wn.cols < (sym_qt_in_line + (args->max_len_arg)))
			{
				ft_putchar_fd('\n', STDWORK);
				sym_qt_in_line = 0;
			}
			ft_printf("%v%s%s%s%-*s%s ", STDWORK, current->color_text,
				current->color_bck ? current->color_bck : "",
				current == args->cur_pos ? args->italics : "",
					args->max_len_arg, current->name, FT_COLOR_DFLT);
			sym_qt_in_line += args->max_len_arg + 1;
			current = current->next;
		}
	}
	else
		EXIT();
}
