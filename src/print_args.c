/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 20:13:13 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/25 16:45:33 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int				wputchar(int c)
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

void			print_selected_args(t_info_args *args)
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

static void		print_args(t_info_args *args)
{
	struct s_arg	*current;
	size_t			sym_qt_in_line;

	sym_qt_in_line = 0;
	current = args->begin;
	while (current)
	{
		if (args->wn.cols < (sym_qt_in_line + (args->max_len_arg + 1)))
		{
			ft_putchar_fd('\n', STDWORK);
			sym_qt_in_line = 0;
		}
		ft_printf("%v%s%s%s%-*s%s%s", STDWORK, current->color_text,
			current->color_bck ? current->color_bck : "",
			current == args->cur_pos ? args->italics : "",
				args->max_len_arg, current->name, FT_COLOR_DFLT,
				current->next ? " " : "");
		sym_qt_in_line += args->max_len_arg + 1;
		current = current->next;
	}
}

void			refresh_screen(t_info_args *args)
{
	size_t	qty_elems_to_col;

	qty_elems_to_col = args->wn.cols / (args->max_len_arg + 1);
	if (!qty_elems_to_col ||
		((args->size / qty_elems_to_col) > (args->wn.rows - 1)))
		print_small_window(args);
	else
	{
		sl_tputs(args->return_cursor, 1, wputchar);
		print_args(args);
		print_info_line(args);
		sl_tputs(args->return_cursor, 1, wputchar);
	}
}
