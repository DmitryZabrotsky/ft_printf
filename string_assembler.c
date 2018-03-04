#include "ft_printf.h"

static int		check_format(t_format *format)
{
	if (format->zero && format->minus)
	{
		format->zero = 0;
		return (1);
	}
	if (format->zero && format->precision)
	{
		format->zero = 0;
		return (2);
	}
	if (format->space && format->plus)
	{
		format->space = 0;
		return (3);
	}
	return (0);
}

char			*assemble_string(t_format *format, va_list args)
{
	check_format(format);
	if (format->type == 'c' || format->type == 'C')
		return (build_c(format, args));
	else if (format->type == 's' || format->type == 'S')
		return (build_s(format, args));
	else
		return (NULL);
}