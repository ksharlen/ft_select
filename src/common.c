#include "ft_select.h"

ssize_t		sl_read(int fd, void *buf, size_t count)
{
	ssize_t	nread;

	nread = read(fd, buf, count);
	if (nread == -1)
		syserror(NULL, "read error: nread = -1");
	return (nread);
}
