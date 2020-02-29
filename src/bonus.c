/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 15:46:33 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/29 14:10:46 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	print_small_window(t_info_args *args)
{
	size_t	center;

	center = (args->wn.cols / 2) - (SIZE_LITTLE_WIN / 2);
	set_pos_cursor(0, 0);
	ft_print_nsym(STDWORK, ' ', args->wn.cols * args->wn.rows);
	set_pos_cursor(center, args->wn.rows / 2);
	write(STDWORK, LITTLE_WIN, SIZE_LITTLE_WIN);
}

void	search_mode(t_info_args *args)
{
	if (args->status & SEARCH_MODE)
	{
		args->status ^= SEARCH_MODE;
		ft_bzero(args->s_buf.buf_search, sizeof(char) * S_SEARCH);
		args->s_buf.len_str = 0;
	}
	else
		args->status |= SEARCH_MODE;
}

size_t	get_pos_curr(t_info_args *args)
{
	struct s_arg	*count;
	size_t			pos;

	pos = 0;
	count = args->begin;
	if (args->begin)
	{
		while (count != args->cur_pos)
		{
			++pos;
			count = count->next;
		}
	}
	return (pos);
}
