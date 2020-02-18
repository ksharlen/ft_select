#include "ft_select.h"

void	print_args(t_info_args *args)
{
	size_t	i;
	size_t	ind_ins;
	char	*ins;
	char	*cl;

	ind_ins = 0;
	ins = sl_tgetstr("us");
	cl = sl_tgetstr("cl");
	i = 0;
	ft_putstr_fd(cl, STDWORK);
	while (i < args->size)
	{
		ft_printf("%v%s%s%s%s ", STDWORK, args->args[i].color, i == ind_ins ? ins : "",
					args->args[i].name, FT_COLOR_DFLT);
		++i;
	}
}
