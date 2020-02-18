/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 15:46:19 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/18 15:53:34 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	str_error(const char *filename, const char *str)
{
	ft_printf("%v%s%s: %s%s\n", STDERR_FILENO, COLOR_ERROR, filename ? filename : "",
		str ? str : "", FT_COLOR_DFLT);
}

void	syserror(const char *filename, const char *str)
{
	str_error(filename, str);
	exit(EXIT_FAILURE);
}

