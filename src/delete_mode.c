/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_mode.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 21:23:06 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/24 22:18:27 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	init_struct_del_mode(struct s_del_mode **sdm)
{
	*sdm = (struct s_del_mode *)ft_memalloc(sizeof(struct s_del_mode));
	ft_chk_null_ptr(*sdm, E_MALLOC);
	(*sdm)->dirname = NULL;
	(*sdm)->status = 0;
}

void	delete_mode(const char *dirname, t_info_args *args)
{
	size_t	len_dirname;

	init_struct_del_mode(&args->sdm);
	args->sdm->dirname = dirname;
	if (*dirname)
	{
		len_dirname = ft_strlen(dirname);
		if (len_dirname > 3)
		{
			//!read only mode
			if (!ft_memcpy((char *)dirname, "../", 3) ||
				!ft_memcpy((char *)dirname, "/", 1))
				args->sdm->status |= READ_FILES;
			else
				args->sdm->status |= DELETE_FILES;
			//!del mode
		}
	}
}

void	delete_file(struct s_arg *current, t_info_args *args)
{
	char	buf[args->max_len_arg + ft_strlen(args->sdm->dirname) + 2];

	ft_bzero(buf, sizeof(buf));
	ft_strcpy(buf, args->sdm->dirname);
	ft_strcat(buf, "/");
	ft_strcat(buf, current->name);
	// if (remove(buf) == -1)
	// {
	// 	ft_printf("%v%sfailed to delete file: %s%s\n", STDERR_FILENO,
	// 		COLOR_ERROR, buf, FT_COLOR_DFLT);
	// 	exit(EXIT_FAILURE);
	// }
	ft_printf("%s\n", buf);
}

void	delete_files(t_info_args *args)
{
	struct s_arg	*current;

	current = args->begin;
	if (args->sdm->status & DELETE_FILES)
	{
		while (current)
		{
			if (current->status & SELECT)
				delete_file(current, args);
			current = current->next;
		}
	}
	exit(EXIT_FAILURE);
	//clean struct
}
