#include "ft_select.h"

void	print_args(t_info_args *args)
{
	struct s_arg	*current;

	if (args->size)
	{
		current = args->begin;
		ft_putstr_fd(args->clear_win, STDWORK);
		while (current)
		{
			ft_printf("%v%s%s%s%s%s ", STDWORK, current->color_text, current->color_bck ? current->color_bck : "",
				current == args->cur_pos ? args->italics : "",
					current->name, FT_COLOR_DFLT);
			current = current->next;
		}
	}
	else
		EXIT();//TODO: TMP
}
