/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 20:12:23 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/19 20:12:24 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

ssize_t		sl_read(int fd, void *buf, size_t count)
{
	ssize_t	nread;

	nread = read(fd, buf, count);
	if (nread == -1)
		syserror(NULL, "read error: nread = -1");
	return (nread);
}
