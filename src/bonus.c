/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 15:46:33 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/24 16:22:51 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	print_last_deleted_elem(t_info_args *args)
{
	char	*str;

	str = sl_tgetstr("cm");
	str = sl_tgoto(str, 0, args->wn.rows);
	sl_tputs(str, 1, wputchar);
	write(STDWORK, DELETE_ELEM, SIZE_STR_DEL_ELEM);
	write(STDWORK, args->lde.name, args->lde.size_name);
}
