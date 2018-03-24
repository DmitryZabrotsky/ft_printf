#include "../../inc/ft_printf.h"

char		*build_s(t_format *format, va_list args)
{
	char	*arg;

	arg = ft_strdup(va_arg(args, char *));
	if (format->precision >= 0)
		set_precision(&arg, format->precision);
	if (format->width)
		arg = set_width(format->minus, format->width, arg);
	return (arg);
}