/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_elem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 20:32:15 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/25 22:05:34 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void		clean_list(t_info_args *args)
{
	free(args->begin);
	args->begin = NULL;
	args->end = NULL;
	args->cur_pos = NULL;
	args->size = 0;
}

static void		delete_last_elem(t_info_args *args)
{
	struct s_arg	*prev_last;

	prev_last = args->end->prev;
	free(args->end);
	prev_last->next = NULL;
	args->end = prev_last;
	args->num_cur_pos--;
	args->cur_pos = prev_last;
}

static void		delete_elem_in_list(t_info_args *args)
{
	struct s_arg	*del;

	del = args->cur_pos;
	args->cur_pos->prev->next = args->cur_pos->next;
	args->cur_pos->next ?
	args->cur_pos->next->prev = args->cur_pos->prev : NULL;
	args->cur_pos = args->cur_pos->prev;
	--args->num_cur_pos;
	free(del);
}

static void		delete_first_elem(t_info_args *args)
{
	struct s_arg *del;

	del = args->cur_pos;
	args->begin = args->begin->next;
	args->begin->prev = NULL;
	args->cur_pos = args->begin;
	free(del);
}

void			delete_elem(t_info_args *args)
{
	if (!(args->status & SEARCH_MODE))
	{
		if (args->size > 1)
		{
			if (args->lde.name)
				ft_strdel((char **)&args->lde.name);
			args->lde.name = args->cur_pos->name;
			args->lde.size_name = args->cur_pos->qt_sym;
			//del = args->cur_pos;
			if (args->cur_pos == args->begin)
				delete_first_elem(args);
			else if (args->end == args->cur_pos)
				delete_last_elem(args);
			else
				delete_elem_in_list(args);
			--args->size;
			ft_print_nsym(STDWORK, ' ', (args->wn.cols) * (args->wn.rows));
		}
		else
			clean_list(args);
	}
	else
		delete_sym_from_search_buf(args);
}
