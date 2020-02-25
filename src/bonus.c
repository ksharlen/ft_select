/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 15:46:33 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/25 14:41:31 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	print_info_line(t_info_args *args)
{
	size_t	shift;

	shift = 0;
	set_pos_cursor(0, args->wn.rows);
	ft_write(STDWORK, DELETE_ELEM, SIZE_STR_DEL_ELEM);
	ft_write(STDWORK, args->lde.name, args->lde.size_name);
	shift = args->wn.cols - SIZE_ROM;
	if (args->sdm && args->sdm->status & READ_FILES)
	{
//TODO: need make defense
		set_pos_cursor(shift, args->wn.rows);
		write(STDOUT_FILENO, READ_ONLY_MODE, SIZE_ROM);
	}
}
