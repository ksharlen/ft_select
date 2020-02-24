/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_filename_dir.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 19:58:10 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/25 01:07:18 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	tmp(t_info_args *args, const char *argv)
{
	struct s_arg	*new;

	new = (struct s_arg *)ft_memalloc(sizeof(struct s_arg));
	ft_chk_null_ptr(new, E_MALLOC);
	new->name = ft_strdup(argv);
	new->qt_sym = ft_strlen(argv);
	if (new->qt_sym > args->max_len_arg)
		args->max_len_arg = new->qt_sym;
	check_colors_file(new);
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
}

static DIR	*sl_opendir(const char *dirname)
{
	DIR	*fd;

	fd = opendir(dirname);
	if (fd == NULL)
		syserror(NULL, "could not open the directory");
	return (fd);
}

static void	get_files(t_info_args *args, DIR *fd)
{
	struct dirent	*dent;

	while ((dent = readdir(fd)))
	{
		if (strcmp(dent->d_name, "..") && strcmp(dent->d_name, "."))
		{
			// init_new_elem(args, dent->d_name);
			tmp(args, dent->d_name);
			args->size++;
		}
	}
	args->cur_pos = args->begin;
}

void	fill_filename_dir(t_info_args *args, const char *dirname)
{
	DIR	*fd;

	args_init(args);
	delete_mode(dirname, args);
	fd = sl_opendir(dirname);
	get_files(args, fd);
	if (closedir(fd) == -1)
		syserror(NULL, "failed to close directory");
	if (!args->size)
		syserror(NULL, "dir is empty");
}
