#include "ft_select.h"

static t_byte	wait_event(void)
{
	ssize_t	nbytes;
	t_byte	sym;

	nbytes = 0;
	while (nbytes == 0)
	{
		nbytes = sl_read(STDWORK, &sym, 1);
		//TODO: chek size_win
	}
	return (sym);
}

static t_key	get_key_arrow(t_byte byte)
{
	t_key	arrow_key;

	arrow_key = KEY_UNKNOW;
	if (byte == 'D')
		arrow_key = KEY_L_ARROW;
	else if (byte == 'C')
		arrow_key = KEY_R_ARROW;
	else if (byte == 'A')
		arrow_key = KEY_U_ARROW;
	else if (byte == 'B')
		arrow_key = KEY_D_ARROW;
	return (arrow_key);
}

static t_key	get_key(void)
{
	t_byte	sym;
	t_key	key;
	ssize_t	nbyte;

	nbyte = sl_read(STDWORK, &sym, 1);
	if (sym == '[')
	{
		sl_read(STDWORK, &sym, 1);
		if (sym >= '0' && sym <= '9')
			;//TODO key combo
		else if (sym >= 'A' && sym <= 'D')
			key = get_key_arrow(sym);
	}
	else if (!nbyte)
		return (KEY_ESC);
	return (key);
}

uint32_t	sl_getch(void)
{
	t_byte	sym;

	P_UNUSED(sym);
	sym = 0;
	sym = wait_event();
	if (sym == '\x1b')
		return (get_key());
	else if (sym >= 32 && sym <= 126)
		return (sym);
	return (sym);
}
