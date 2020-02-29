/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_elem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 21:52:52 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/29 14:12:57 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void		delete_sym_from_search_buf(t_info_args *args)
{
	if (args->s_buf.len_str)
		args->s_buf.buf_search[args->s_buf.len_str-- - 1] = 0;
}

static void	find_a_match(t_info_args *args)
{
	struct s_arg *current;

	current = args->begin;
	while (current)
	{
		if (!ft_memcmp(current->name, args->s_buf.buf_search,
			args->s_buf.len_str))
		{
			args->cur_pos = current;
			args->num_cur_pos = get_pos_curr(args);
			break ;
		}
		current = current->next;
	}
}

void		search_elem(t_info_args *args, t_key sym)
{
	if (args->status & SEARCH_MODE)
	{
		ft_strcat(args->s_buf.buf_search, (char *)&sym);
		++args->s_buf.len_str;
		find_a_match(args);
	}
}
