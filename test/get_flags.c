/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 19:03:46 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/24 20:46:03 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	get_flag(t_info_args *args, char flag)
{
	if (flag == 'r')
		args->status |= REV_MODE;
	else if (flag == 'd')
		args->status |= DEL_MODE;
}

void	get_flags(t_info_args *args, int *argc, char ***argv)
{
	char	**p_argv;

	--(*argc);
	p_argv = *argv;
	++p_argv;
	if (*argc > 0)
	{
		args->status = 0;
		if (p_argv[0][0] == '-')
		{
			if (p_argv[0][1])
			{
				get_flag(args, p_argv[0][1]);
				if (p_argv[0][2])
					get_flag(args, p_argv[0][2]);
			}
			++p_argv;
			--(*argc);
		}
	}
	*argv = p_argv;
}
