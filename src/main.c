/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 15:26:57 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/24 20:14:43 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

struct termios	g_cpy;

int			main(int argc, char **argv)
{
	struct s_init	init;
	t_info_args		args;

	get_flags(&args, &argc, &argv);
	if (argc > 0)
	{
		init_term(&init);
		if (args.status & DEL_MODE && argc == 1 && *argv)
			fill_filename_dir(&args, *argv);
		else
			convert_args_to_array(argc, argv, &args);
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
