/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_limits.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 15:32:39 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/19 01:52:49 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIMITS_H
# define FT_LIMITS_H

# include <limits.h>

# include "libft.h"

# define COLOR_C_FILE	"\x1b[38;2;255;204;0m"
# define COLOR_O_FILE	"\x1b[38;2;0;255;255m"
# define COLOR_ERROR	"\x1b[38;2;255;43;43m"
//TODO

# define STDWORK 2

//!TMP
# define P_UNUSED(var) (void)(var)

# define EXIT() exit(EXIT_FAILURE)

typedef uint32_t	t_key;
typedef uint8_t		t_byte;

#endif