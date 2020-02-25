/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_limits.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 15:32:39 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/25 15:22:19 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIMITS_H
# define FT_LIMITS_H

# include <limits.h>

# include "libft.h"

# define SELECT					1
# define COLOR_FILE				2
# define REV_MODE				4
# define DEL_MODE				8
# define C_FILE					256
# define O_FILE					512
# define MAKEFILE				1024

# define READ_FILES				1
# define DELETE_FILES			2

# define COLOR_DFLT				"\x1b[38;2;255;255;255m"
# define COLOR_C_FILE			"\x1b[38;2;255;204;0m"
# define COLOR_O_FILE			"\x1b[38;2;0;255;255m"
# define COLOR_ERROR			"\x1b[38;2;255;43;43m"
# define COLOR_BLACK			"\x1b[38;2;0;0;0m"

# define COLOR_BCK_C			"\x1b[48;2;255;204;0m"
# define COLOR_BCK_O			"\x1b[48;2;0;255;255m"
# define COLOR_BCK_DFLT			"\x1b[48;2;255;255;255m"
# define NON_COLOR_BCK			"\x1b[49m"
# define COLOR_LINE_STAT		"\x1b[48;2;40;40;40m"
# define COLOR_R_MODE			"\x1b[48;2;205;197;194m"
# define COLOR_STAT_TEXT		"\x1b[38;2;"

# define DELETE_ELEM			"Last deleted: "
# define READ_ONLY_MODE			"read only mode"

# define SIZE_ROM				14
# define SIZE_STR_DEL_ELEM		14

# define STDWORK				2

typedef uint32_t		t_key;
typedef uint8_t			t_byte;

#endif
