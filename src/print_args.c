#include "ft_select.h"

// int		sl_putchar(int c)
// {
// 	write(STDWORK, &c, 1);
// 	return (c);
// }

// void	print_args(t_info_args *args)
// {
// 	size_t	i;
// 	char	*ins;
// 	char	*cl;

// 	ins = sl_tgetstr("us");
// 	cl = sl_tgetstr("cl");
// 	i = 0;
// 	ft_putstr_fd(cl, STDWORK);
// 	while (i < args->size)
// 	{
// 		if (args->args[i].status == NOT_DELETED)
// 			ft_printf("%v%s%s%s%s ", STDWORK, args->args[i].color, i == args->ind_ins ? ins : "",
// 						args->args[i].name, FT_COLOR_DFLT);
// 		++i;
// 	}
// }

void	print_args(t_info_args *args)
{
	struct s_arg	*current;

	if (args->size)
	{
		current = args->begin;
		ft_putstr_fd(args->clear_win, STDWORK);
		while (current)
		{
			ft_printf("%v%s%s%s%s ", STDWORK, current->color_text,
				current == args->cur_pos ? args->italics : "",
					current->name, FT_COLOR_DFLT);
			current = current->next;
		}
	}
	else
		EXIT();//TODO: TMP
}
