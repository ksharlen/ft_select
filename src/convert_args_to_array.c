/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_args_to_array.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 16:21:19 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/19 01:01:15 by ksharlen         ###   ########.fr       */
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

// static	void	init_arg(struct s_arg *arg, const char *argv)
// {
// 	arg->name = argv;
// 	arg->qt_sym = ft_strlen(arg->name);
// 	arg->status = NOT_DELETED;
// 	arg->color = FT_COLOR_DFLT;
// }

static void	init_new_elem(t_info_args *args, const char *argv)
{
	struct s_arg	*new;

	new = (struct s_arg *)ft_memalloc(sizeof(struct s_arg));
	ft_chk_null_ptr(new, E_MALLOC);
	new->name = argv;
	new->qt_sym = ft_strlen(argv);
	new->status = NOT_DELETED;
	new->color = FT_COLOR_DFLT;
	if (args->begin == NULL)
	{
		args->begin = new;
		new->prev = NULL;
	}
	else
	{
		new->prev = args->end;
		args->end->next = new;
	}
	new->next = NULL;
	args->end = new;
	//TODO: need free
}

static void	convert_args(t_info_args *args,
	const size_t argc, char *const *argv)
{
	size_t	i;

	i = 0;
	while (i < argc)
	{
		if (*argv[i])
		{
			init_new_elem(args, argv[i]);
		}
		++i;
	}
}

// static void tmp(struct s_arg *beg)
// {
// 	while (beg)
// 	{
// 		printf("name: %s	qt_sym: %zd\n", beg->name, beg->qt_sym);
// 		beg = beg->next;
// 	}
// 	EXIT();
// }

// {
// 	// ft_printf("%v%s\n", STDWORK, ((struct s_arg *)beg->data)->name);
// 	write(STDWORK, ((struct s_arg *)beg->data)->name, ((struct s_arg *)beg->data)->qt_sym);
// 	EXIT();
// }

t_info_args		convert_args_to_array(const int argc, char *const *argv)
{
	t_info_args	args;

	args.begin = NULL;
	args.end = NULL;
	args.size = get_size_args(argc, argv);
	if (args.size)
		convert_args(&args, argc, argv);
	else
		syserror(NULL, "arg or args is empty strings");
// tmp(args.begin);
	// args.ind_ins = 0;
	args.cur_pos = args.begin;
	return (args);
}
