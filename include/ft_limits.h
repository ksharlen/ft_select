/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_limits.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 15:32:39 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/19 00:23:49 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIMITS_H
# define FT_LIMITS_H

# include <limits.h>

# include "libft.h"

# define COLOR_C_FILE
# define COLOR_O_FILE
# define COLOR_ERROR	"\x1b[38;2;255;43;43m"
//TODO

# define STDWORK 2

//!TMP
# define P_UNUSED(var) (void)(var)

# define EXIT() exit(EXIT_FAILURE)

typedef uint32_t	t_key;
typedef uint8_t		t_byte;

#endif