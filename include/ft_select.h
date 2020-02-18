/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 15:19:23 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/18 16:27:42 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <termios.h>
# include <termcap.h>

# include "libft.h"
# include "ft_limits.h"
# include "struct.h"

void	canon(struct termios *cpy_cfg);
void	no_canon(struct termios *cpy_cfg);

void	str_error(const char *filename, const char *str);
void	syserror(const char *filename, const char *str);

void	init_term(struct s_init *init);

/*
**TERMCAP
*/
void	sl_tgetent(char *vterm);
char	*sl_tgetstr(char *cb);
char	*sl_tgoto(char *cb, int one, int two);
void	sl_tputs(const char *str, int affcnt, int (*putc)(int));
int		sl_tgetnum(char *str);

t_info_args	convert_args_to_array(const int argc, char *const *argv);

#endif