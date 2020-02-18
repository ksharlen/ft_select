/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_keypress.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 16:48:53 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/19 01:23:48 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	move_position(t_info_args *args, t_key key)
{
	if (key == KEY_L_ARROW)
	{
		args->cur_pos = args->cur_pos->prev ? args->cur_pos->prev : args->end;
	}
	else if (key == KEY_R_ARROW)
	{
		args->cur_pos = args->cur_pos->next ? args->cur_pos->next : args->begin;
	}
}

// static void	move_position(t_info_args *args, t_key key)
// {
// 	if (key == KEY_L_ARROW)
// 		args->ind_ins = !args->ind_ins ? args->size - 1 : args->ind_ins - 1;
// 	else if (key == KEY_R_ARROW)
// 		args->ind_ins = args->ind_ins == args->size - 1 ? 0 : args->ind_ins + 1;
// 	else if (key == KEY_U_ARROW)
// 	{
// 		//TODO
// 	}
// 	else if (key == KEY_D_ARROW)
// 	{
// 		//TODO
// 	}
// }

// static void	delete_curr_elem(t_info_args *args)
// {
// 	// EXIT();
// 	args->args[args->ind_ins].status = DELTED;
// }

void	process_keypress(t_info_args *args)
{
	int		key;

	P_UNUSED(args);
	P_UNUSED(key);
	key = 0;
	// print_args(args);
	while (key != KEY_ESC)
	{
		print_args(args);
		key = sl_getch();
		if (key == KEY_L_ARROW || key == KEY_R_ARROW ||
			key == KEY_U_ARROW || key == KEY_D_ARROW)
			move_position(args, key);
		// 	move_position(args, key);
		// // else if (key == KEY_BACKSPACE)
		// 	// delete_curr_elem(args);
		// print_args(args);
	}
}
