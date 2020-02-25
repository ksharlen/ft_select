/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arrow_keys.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 15:54:11 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/23 20:09:03 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	parse_arrow_left_right(t_info_args *args, t_key key)
{
	if (key == KEY_L_ARROW)
	{
		args->num_cur_pos = args->cur_pos->prev ?
		args->num_cur_pos - 1 : (int32_t)args->size - 1;
		args->cur_pos = args->cur_pos->prev ?
		args->cur_pos->prev : args->end;
	}
	else if (key == KEY_R_ARROW)
	{
		args->num_cur_pos = args->cur_pos->next ?
		args->num_cur_pos + 1 : 0;
		args->cur_pos = args->cur_pos->next ?
		args->cur_pos->next : args->begin;
	}
}

static void	parse_arrow_up(t_info_args *args, ssize_t line)
{
	ssize_t	i;
	ssize_t	weight;

	weight = args->num_cur_pos - line;
	i = 0;
	if (weight >= 0)
	{
		while (i < line)
		{
			args->cur_pos = args->cur_pos->prev;
			++i;
		}
		args->num_cur_pos -= line;
	}
}

static void	parse_arrow_down(t_info_args *args, ssize_t line)
{
	ssize_t	i;

	i = 0;
	if (args->size > ((size_t)args->num_cur_pos + line))
	{
		while (i < line)
		{
			args->cur_pos = args->cur_pos->next;
			++i;
		}
		args->num_cur_pos += line;
	}
}

void		move_position(t_info_args *args, t_key key)
{
	ssize_t	line;

	if (key == KEY_L_ARROW || key == KEY_R_ARROW)
		parse_arrow_left_right(args, key);
	else if (((args->max_len_arg * args->size) / args->wn.cols +
		((args->max_len_arg * args->size) % args->wn.cols ? 1 : 0)) > 1)
	{
		line = (args->wn.cols / (args->max_len_arg + 1));
		if (key == KEY_D_ARROW)
			parse_arrow_down(args, line);
		else
			parse_arrow_up(args, line);
	}
}
