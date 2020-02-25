/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 20:02:04 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/25 22:03:35 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	draw_status_line(size_t row, size_t pos,
	size_t ncols, const char *color)
{
	set_pos_cursor(pos, row);
	ft_printf("%v%s%*s", STDWORK, color,
		ncols, "");
	set_pos_cursor(pos, row);
}

static void		draw_search_mode(t_info_args *args, size_t *shift)
{
	set_pos_cursor(*(shift), args->wn.rows);
	ft_write(STDWORK, STR_SEARCH_MODE, SIZE_SEARCH_MODE);
	ft_putstr_fd(args->s_buf.buf_search, STDWORK);
}

static size_t	draw_r_only_mode(t_info_args *args)
{
	size_t	shift;

	draw_status_line(args->wn.rows, 0, SIZE_ROM, COLOR_R_MODE);
	ft_printf("%s", COLOR_BLACK);
	shift = ft_write(STDWORK, READ_ONLY_MODE, SIZE_ROM) + 1;
	draw_status_line(args->wn.rows, SIZE_ROM, 0, COLOR_LINE_STAT);
	return (shift);
}

static void		draw_delete_mode(t_info_args *args, size_t *shift)
{
	set_pos_cursor(*shift, args->wn.rows);
	*shift += ft_write(STDWORK, DELETE_ELEM, SIZE_STR_DEL_ELEM);
	*shift += ft_write(STDWORK, args->lde.name, args->lde.size_name) + 1;
}

void	print_info_line(t_info_args *args)
{
	size_t	shift;

	shift = 0;
	draw_status_line(args->wn.rows, 0, args->wn.cols, COLOR_LINE_STAT);
	if (args->sdm && args->sdm->status & READ_FILES)
		shift += draw_r_only_mode(args);
	draw_status_line(args->wn.rows, shift, 0, COLOR_DFLT);
	if (args->status & SEARCH_MODE)
		draw_search_mode(args, &shift);
	else
		draw_delete_mode(args, &shift);
	draw_status_line(args->wn.rows, shift, 0, FT_COLOR_DFLT);
	//TODO: here will search_mode
}
