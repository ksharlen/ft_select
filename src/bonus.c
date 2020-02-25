/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 15:46:33 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/25 17:11:05 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	search_mode(t_info_args *args)
{
	if (args->status & SEARCH_MODE)
		args->status ^= SEARCH_MODE;
	else
		args->status |= SEARCH_MODE;
}
