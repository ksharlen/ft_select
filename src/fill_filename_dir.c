/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_filename_dir.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 19:58:10 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/24 20:24:22 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

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
			init_new_elem(args, dent->d_name);
			args->size++;
		}
	}
	args->cur_pos = args->begin;
}

void	fill_filename_dir(t_info_args *args, const char *dirname)
{
	DIR	*fd;

	args_init(args);
	fd = sl_opendir(dirname);
	get_files(args, fd);
}
