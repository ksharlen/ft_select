/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 15:46:33 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/25 21:36:03 by ksharlen         ###   ########.fr       */
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
		args->status ^= SEARCH_MODE;
	else
		args->status |= SEARCH_MODE;
}
