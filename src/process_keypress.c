/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_keypress.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 16:48:53 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/29 14:09:14 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void			select_elem(t_info_args *args)
{
	if (args->status & REV_MODE)
		revers_word((char *)args->cur_pos->name);
	if (args->cur_pos->status & SELECT)
	{
		args->cur_pos->status ^= (uint32_t)SELECT;
		unset_color_selected_elem(args->cur_pos);
	}
	else
	{
		args->cur_pos->status |= SELECT;
		set_color_selected_elem(args->cur_pos);
		if (args->cur_pos->next)
		{
			args->cur_pos = args->cur_pos->next;
			++args->num_cur_pos;
		}
		else
		{
			args->cur_pos = args->begin;
			args->num_cur_pos = 0;
		}
	}
}

void			process_keypress(t_info_args *args)
{
	int		key;

	key = 0;
	while (args->size)
	{
		refresh_screen(args);
		key = sl_getch(args);
		if (key == KEY_L_ARROW || key == KEY_R_ARROW ||
			key == KEY_U_ARROW || key == KEY_D_ARROW)
			move_position(args, key);
		else if (key == KEY_BACKSPACE || key == KEY_DEL)
			delete_elem(args);
		else if (key == KEY_SPACE)
			select_elem(args);
		else if (key == KEY_ENTER)
			break ;
		else if (key == KEY_CTRL_F)
			search_mode(args);
		else if (key == KEY_ESC)
		{
			canon(&g_cpy);
			exit(EXIT_SUCCESS);
		}
		else if (key >= 32 && key <= 126)
			search_elem(args, key);
	}
}
