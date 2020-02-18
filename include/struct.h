/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 15:28:34 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/18 16:23:51 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include <sys/types.h>

# include "libft.h"

enum			e_status_arg
{
	DELTED,
	NOT_DELETED
};

struct			s_arg
{
	char	*name;
	size_t	qt_sym;
	int		color;
	int		status;
};

typedef	struct	s_info_args
{
	struct s_arg	*args;
	size_t			size;
}				t_info_args;

struct			s_win
{
	size_t		cols;
	size_t		rows;
};

struct			s_cursor
{
	size_t		x;
	size_t		y;
};

struct		s_init
{
	char	*tty_name;
	char	*vterm;
};

#endif