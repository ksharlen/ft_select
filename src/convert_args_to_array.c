/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_args_to_array.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 16:21:19 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/18 16:48:02 by ksharlen         ###   ########.fr       */
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

static	void	init_arg(struct s_arg *arg, const char *argv)
{
	arg->name = argv;
	arg->qt_sym = ft_strlen(arg->name);
	arg->status = NOT_DELETED;
	arg->color = FT_COLOR_DFLT;
}

static struct	s_arg	*convert_args(const size_t argc, char *const *argv,
	size_t size_new_arr)
{
	size_t	i;
	size_t	j;
	struct s_arg	*args;

	i = 0;
	j = 0;
	args = (struct s_arg *)ft_memalloc((sizeof(struct s_arg) * size_new_arr));
	ft_chk_null_ptr(args, E_MALLOC);
	while (i < argc)
	{
		if (*argv[i])
		{
			init_arg(&args[j], argv[i]);
			++j;
		}
		++i;
	}
	return (args);
}

// void	tmp(t_info_args *args)
// {
// 	size_t	i = 0;

// 	while (i < args->size)
// 	{
// 		ft_printf("arg[%zd]->name: %s\n", i, args->args[i].name);
// 		ft_printf("arg[%zd]->len: %zd\n", i, args->args[i].qt_sym);
// 		ft_printf("arg[%zd]->status: %s\n", i, args->args[i].status == NOT_DELETED ? "not_deleted" : "deleted");
// 		ft_printf("arg[%zd]->color: %s\n", i, args->args[i].color);
// 		++i;
// 	}
// }

t_info_args		convert_args_to_array(const int argc, char *const *argv)
{
	t_info_args	args;

	args.size = get_size_args(argc, argv);
	if (args.size)
	{
		args.args = convert_args(argc, argv, args.size);
// tmp(&args);
	}
	else
		syserror(NULL, "arg or args is empty strings");
	args.ind_ins = 0;
	return (args);
}
