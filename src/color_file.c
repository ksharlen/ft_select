/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 01:44:01 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/19 01:52:24 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	set_colors_file(struct s_arg *elem)
{
	char	*sym;

	if ((sym = strrchr(elem->name, '.')))
	{
		++sym;
		{
			if (*sym && *sym == 'o')
			{
				elem->color_text = COLOR_O_FILE;
			}
			else if (*sym == 'c')
			{
				elem->color_text = COLOR_C_FILE;
			}
			else
			{
				elem->color_text = FT_COLOR_DFLT;
			}
		}
	}
	else
		elem->color_text = FT_COLOR_DFLT;
}
