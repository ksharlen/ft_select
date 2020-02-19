/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 20:13:13 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/19 20:50:09 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	print_args(t_info_args *args)
{
	struct s_arg	*current;

	if (args->size)
	{
		current = args->begin;
		ft_putstr_fd(args->clear_win, STDWORK);
		while (current)
		{
			ft_printf("%v%s%s%s%-*s%s ", STDWORK, current->color_text,
				current->color_bck ? current->color_bck : "",
				current == args->cur_pos ? args->italics : "",
					args->max_len_arg, current->name, FT_COLOR_DFLT);
			current = current->next;
		}
	}
	else
		EXIT();
}
