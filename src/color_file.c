/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 01:44:01 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/19 19:14:05 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	set_color_file(struct s_arg *elem, char *sym)
{
	if (*sym)
	{
		if (*sym == 'o')
		{
			elem->status |= COLOR_FILE;
			elem->status |=	O_FILE;
			elem->color_text = COLOR_O_FILE;
			elem->color_bck = NULL;
			return ;
		}
		else if (*sym == 'c')
		{
			elem->status |= C_FILE;
			elem->status |= COLOR_FILE;
			elem->color_text = COLOR_C_FILE;
			elem->color_bck = NULL;
			return ;
		}
	}
	elem->color_text = COLOR_DFLT;
	elem->color_bck = NULL;
}

void	check_colors_file(struct s_arg *elem)
{
	char	*sym;

	if ((sym = strrchr(elem->name, '.')))
		set_color_file(elem, sym + 1);
	else
	{
		elem->color_text = COLOR_DFLT;
		elem->color_bck = NON_COLOR_BCK;
	}
}

void	set_color_selected_elem(struct s_arg *elem)
{
	if (elem->status & COLOR_FILE)
	{
		if (elem->status & C_FILE)
			elem->color_bck = COLOR_BCK_C;
		else if (elem->status & O_FILE)
			elem->color_bck = COLOR_BCK_O;
	}
	else
	{
		elem->color_bck = COLOR_BCK_DFLT;
	}
	elem->color_text = COLOR_BLACK;
}

void	unset_color_selected_elem(struct s_arg *elem)
{
	P_UNUSED(elem);
	// elem->color_bck = 
}
