/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_keypress.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 16:48:53 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/18 17:10:04 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	process_keypress(t_info_args *args)
{
	int		key;

	P_UNUSED(args);
	P_UNUSED(key);
	key = 0;
	write(STDWORK, "\e[2J", 4);
	write(STDWORK, "\e[H", 3);
	while (key != '\n')
	{
		read(STDERR_FILENO, &key, 1);
		// ft_printf("%vkey: %d\n", STDERR_FILENO, key);
		// write(STDWORK, &key, 1);
	}
}
