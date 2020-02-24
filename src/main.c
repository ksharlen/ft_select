/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 15:26:57 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/24 19:16:58 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

struct termios	g_cpy;

int			main(int argc, char **argv)
{
	struct s_init	init;
	t_info_args		args;

	if (argc > 1)
	{
		get_flags(&args, &argc, &argv);
//!TMP
size_t i = 0;

while (i < (size_t)argc)
{
	ft_printf("%zd) %s\n", i, argv[i]);
	++i;
}
exit(EXIT_FAILURE);
//!TMP
		init_term(&init);
		convert_args_to_array(argc - 1, argv + 1, &args);
		no_canon(&g_cpy);
		init_termcap(&args);
		signals_handler();
		process_keypress(&args);
		canon(&g_cpy);
		print_selected_args(&args);
		delete_list(&args);
	}
	return (0);
}
