/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 15:26:57 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/23 20:55:13 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

struct termios	g_cpy;

void	check_reverse_flag(t_info_args *args, int *argc, char ***argv)
{
	char	**p_argv;

	p_argv = (*argv);
	args->status = 0;
	if (*argc > 1)
	{
		if (p_argv[1][0] == '-' && p_argv[1][1] == 'r')
		{
			args->status |= REV_MODE;
			--(*argc);
			++(*argv);
		}
	}
}

int		main(int argc, char **argv)
{
	struct s_init	init;
	t_info_args		args;

	check_reverse_flag(&args, &argc, &argv);
	if (argc > 1)
	{
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
