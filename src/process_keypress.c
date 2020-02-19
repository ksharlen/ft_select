/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_keypress.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 16:48:53 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/20 00:13:21 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void		move_position(t_info_args *args, t_key key)
{
	if (key == KEY_L_ARROW)
	{
		args->num_cur_pos = args->cur_pos->prev ? args->num_cur_pos - 1 : args->size - 1;
		args->cur_pos = args->cur_pos->prev ?
		args->cur_pos->prev : args->end;
	}
	else if (key == KEY_R_ARROW)
	{
		args->num_cur_pos = args->cur_pos->next ? args->num_cur_pos + 1 : 0;
		args->cur_pos = args->cur_pos->next ?
		args->cur_pos->next : args->begin;
	}
	else if (key == KEY_D_ARROW)
	{
		ssize_t	i = 0;
		ssize_t	line = ((args->wn.cols - (args->wn.cols / args->max_len_arg)) / (args->max_len_arg));

		if (args->num_cur_pos + line < (ssize_t)args->size)
		{
			while (i < line)
			{
				++i;
				if (!args->cur_pos->next)
					args->cur_pos = args->begin;
				args->cur_pos = args->cur_pos->next;
			}
			args->num_cur_pos += line;
		}
	}
	else if (key == KEY_U_ARROW)
	{
		ssize_t	i = 0;
		ssize_t	line = ((args->wn.cols - (args->wn.cols / args->max_len_arg)) / (args->max_len_arg));

		if (args->num_cur_pos - line >= 0)
		{
			while (i < line)
			{
				++i;
				args->cur_pos = args->cur_pos->prev;
			}
			args->num_cur_pos -= line;
		}
	}
}

void			clean_list(t_info_args *args)
{
	free(args->begin);
	args->begin = NULL;
	args->end = NULL;
	args->cur_pos = NULL;
	args->size = 0;
}

static void		delete_elem(t_info_args *args)
{
	struct s_arg	*del;

	if (args->size > 1)
	{
		del = args->cur_pos;
		if (args->cur_pos == args->begin)
		{
			args->begin = args->begin->next;
			args->begin->prev = NULL;
			args->cur_pos = args->begin;
		}
		else
		{
			args->cur_pos->prev->next = args->cur_pos->next;
			args->cur_pos->next ?
			args->cur_pos->next->prev = args->cur_pos->prev : NULL;
			args->cur_pos = args->cur_pos->prev;
		}
		free(del);
		--args->size;
		--args->num_cur_pos;
	}
	else
		clean_list(args);
}

void			select_elem(t_info_args *args)
{
	if (args->cur_pos->status & SELECT)
	{
		args->cur_pos->status ^= (uint32_t)SELECT;
		unset_color_selected_elem(args->cur_pos);
	}
	else
	{
		args->cur_pos->status |= SELECT;
		set_color_selected_elem(args->cur_pos);
	}
}

void			process_keypress(t_info_args *args)
{
	int		key;

	key = 0;
	while (key != KEY_ESC && args->size)
	{
		print_args(args);
		key = sl_getch(args);
		if (key == KEY_L_ARROW || key == KEY_R_ARROW ||
			key == KEY_U_ARROW || key == KEY_D_ARROW)
			move_position(args, key);
		else if (key == KEY_BACKSPACE)
			delete_elem(args);
		else if (key == KEY_SPACE)
			select_elem(args);
	}
}
