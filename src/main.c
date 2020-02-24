/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 15:26:57 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/24 22:17:23 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

struct termios	g_cpy;

static void	select_mode(t_info_args *args, int argc, char **argv)
{
	if (args->status & DEL_MODE)
	{
		if (argc == 1)
		{
			if (*argv)
				fill_filename_dir(args, *argv);//TODO
			else
				syserror(NULL, "dirname is emtpy string");
		}
		else
			syserror(NULL, "a few arguments");
	}
	else
		convert_args_to_array(argc, argv, args);
}

int			main(int argc, char **argv)
{
	struct s_init		init;
	t_info_args			args;

	get_flags(&args, &argc, &argv);
	if (argc > 0)
	{
		init_term(&init);
		select_mode(&args, argc, argv);
		no_canon(&g_cpy);
		init_termcap(&args);
		signals_handler();
		process_keypress(&args);
		canon(&g_cpy);
		if (args.status & DEL_MODE)
			delete_files(&args);//TODO DELETE
		else
			print_selected_args(&args);
		delete_list(&args);
	}
	return (0);
}
