#include "../../inc/ft_printf.h"

char		*build_s(t_format *format, va_list args)
{
	char	*arg;
	wchar_t *wchr;

	if (format->type == 'S' || ft_strequ(format->size, "l"))
	{
		wchr = va_arg(args, wchar_t *);
		if (wchr)
			arg = ft_wstrtostr(wchr);
		else
			arg = ft_strdup("(null)");
	}
	else
		arg = va_arg(args, char *);
		if (!arg)
			arg = ft_strdup("(null)");
		else 
			arg = ft_strdup(arg);
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