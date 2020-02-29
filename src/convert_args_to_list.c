/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_args_to_list.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 16:21:19 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/29 14:19:52 by ksharlen         ###   ########.fr       */
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

static void		convert_args(t_info_args *args,
	const size_t argc, char *const *argv)
{
	size_t	i;

	i = 0;
	while (i < argc)
	{
		if (*argv[i])
			init_new_elem(args, argv[i]);
		++i;
	}
}

void			convert_args_to_array(int argc,
	char *const *argv, t_info_args *args)
{
	args_init(args);
	args->size = get_size_args(argc, argv);
	if (args->size)
		convert_args(args, argc, argv);
	else
		syserror(NULL, "arg or args is empty strings");
	args->cur_pos = args->begin;
}
