#include "../../inc/ft_printf.h"

int		handle_width(const char *fstr, t_format *format, va_list args)
{
	int i;
	int width;

	i = 0;
	if (fstr[i] == '*')
	{
		width = va_arg(args, int);
		i++;
	}
	else
	{
		while (ft_isdigit(fstr[i]))
			i++;
		width = ft_atoi(fstr);
	}
	if (width < 0)
	{
		format->width = width * -1;
		if (!format->minus)
			format->minus = 1;
	}
	else
		format->width = width;
	return (i);
}