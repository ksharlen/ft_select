/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 15:19:23 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/19 22:31:05 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <termios.h>
# include <termcap.h>
# include <sys/ioctl.h>
# include <stdio.h>

# include "libft.h"
# include "ft_dbl_list_cycl.h"
# include "ft_limits.h"
# include "struct.h"

void		canon(struct termios *cpy_cfg);
void		no_canon(struct termios *cpy_cfg);

void		str_error(const char *filename, const char *str);
void		syserror(const char *filename, const char *str);

void		init_term(struct s_init *init);
void		init_termcap(t_info_args *args);

/*
**TERMCAP
*/
void		sl_tgetent(char *vterm);
char		*sl_tgetstr(char *cb);
char		*sl_tgoto(char *cb, int one, int two);
void		sl_tputs(const char *str, int affcnt, int (*putc)(int));
int			sl_tgetnum(char *str);

t_info_args	convert_args_to_array(const int argc, char *const *argv);
void		process_keypress(t_info_args *args);

ssize_t		sl_read(int fd, void *buf, size_t count);
uint32_t	sl_getch(t_info_args *args);
void		print_args(t_info_args *args);

int			sl_putchar(int c);
void		check_colors_file(struct s_arg *elem);
void		set_color_selected_elem(struct s_arg *elem);
void		unset_color_selected_elem(struct s_arg *elem);
void		get_win_size(struct s_win *wn);
void		screen_update(t_info_args *args, struct s_win *wn);
int			wputchar(int c);

#endif
