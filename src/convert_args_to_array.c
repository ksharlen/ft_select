/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_args_to_array.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 16:21:19 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/18 16:28:56 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static size_t	get_size_args(const int argc, char *const *argv)
{
	size_t	i;
	size_t	qt_not_empty_args;

	i = 0;
	qt_not_empty_args = 0;
	while (i < (size_t)argc)
	{
		if (*argv[i])
			++qt_not_empty_args;
		++i;
	}
	return (qt_not_empty_args);
}

t_info_args		convert_args_to_array(const int argc, char *const *argv)
{
	t_info_args	args;

	args.size = get_size_args(argc, argv);
	printf("size: %zd\n", args.size);
exit(EXIT_FAILURE);
	return (args);
}
