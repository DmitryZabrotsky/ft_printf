#include "../../inc/ft_printf.h"

char		*build_s(t_format *format, va_list args)
{
	char	*arg;

	if (format->type == 'S' || ft_strequ(format->size, "l"))
		arg = ft_wstrtostr(va_arg(args, wchar_t *));
	else
		arg = ft_strdup(va_arg(args, char *));
	if (format->precision >= 0)
	{
		if (format->type == 'S' || ft_strequ(format->size, "l"))
		{
			while (arg[format->precision] < -63 )
				format->precision--;
		}
		set_precision(&arg, format->precision);
	}
	if (format->width)
		arg = set_width(format->minus, format->width, arg);
	return (arg);
}