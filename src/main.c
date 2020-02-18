/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 15:26:57 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/18 16:28:24 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		main(int argc, char **argv)
{
	struct s_init	init;
	struct termios	cpy;
	t_info_args		args;

	P_UNUSED(argc);
	P_UNUSED(argv);
	P_UNUSED(args);
	if (argc > 1)
	{
		init_term(&init);
		args = convert_args_to_array(argc - 1, argv + 1);
		no_canon(&cpy);
		// proccess_keypess();
		canon(&cpy);
	}
	return (0);
}
