#include "ft_printf.h"

static int		handle_flag(char fchr, t_format *format)
{
	if (fchr == '-') 
		return (format->minus = 1);
	if (fchr == '+')
		return (format->plus = 1);
	if (fchr == ' ')
		return (format->space = 1);
	if (fchr == '#')
		return (format->hash = 1);
	if (fchr == '0')
		return (format->zero = 1);
	return (0);
}

int				handle_flags(char *fstr, t_format *format)
{
	int			i;

	i = 0;
	while (handle_flag(fstr[i], format))
		i++;
	return (i);
}
