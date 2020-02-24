/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 15:28:34 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/24 15:32:25 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include <sys/types.h>

# include "libft.h"

enum			e_status_arg
{
	SELECTED,
	NOT_SELECTED
};

enum			e_key
{
	KEY_L_ARROW = 1000,
	KEY_R_ARROW,
	KEY_U_ARROW,
	KEY_D_ARROW,
	KEY_ESC,
	KEY_BACKSPACE,
	KEY_ENTER,
	KEY_DEL,
	KEY_UNKNOW,
	KEY_SPACE = 32,
};

struct				s_arg
{
	struct s_arg	*next;
	struct s_arg	*prev;
	size_t			qt_sym;
	int				status;
	char			*color_text;
	char			*color_bck;
	const char		*name;
};

struct				s_win
{
	size_t		cols;
	size_t		rows;
};

typedef	struct		s_info_args
{
	struct s_win	wn;
	struct s_arg	*begin;
	struct s_arg	*end;
	struct s_arg	*cur_pos;
	size_t			size;
	uint32_t		status;
	uint32_t		max_len_arg;
	int32_t			num_cur_pos;
	char			*italics;
	char			*return_cursor;
}					t_info_args;

struct				s_init
{
	char	*tty_name;
	char	*vterm;
};

#endif
