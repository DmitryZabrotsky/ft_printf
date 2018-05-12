#include "../../inc/ft_printf.h"

static unsigned char		take_c(va_list args)
{
	return ((unsigned char)va_arg(args, int));
}

static char					*make_str(t_format *format, char chr)
{
	char *str;

	if (format->width)
	{
		str = ft_strnew(format->width);
		str = (char *)(ft_memset(str, ' ', format->width));
		if (format->minus)
			str[0] = chr;
		else
			str[format->width - 1] = chr;
		return (str);
	}
	else
	{
		str = ft_strnew(1);
		str[0] = chr;
		return (str);
	}
}

static char					*make_wchar(t_format *format, va_list args)
{
	char					*res;
	wint_t					arg;

	arg = va_arg(args, wint_t);
	if (!arg)
		return (make_str(format, (char)arg));
	else
	{
		res = ft_wchartochar((wchar_t)arg);
		if (MB_CUR_MAX != 4 && arg > 127)
		{
			return (make_str(format, (char)arg));
		}
		if (format->width)
			ft_mleak(&res, set_width(format->minus, format->width, res));
		return (res);
	}
}

char						*build_c(t_format *format, va_list args)
{
	char					chr;
	char					*res;

	res = NULL;
	chr = '\0';
	if (format->type == 'C' || (ft_strequ(format->size, "l") &&
		format->type == 'c'))
		res = make_wchar(format, args);
	else if (format->type == 'c')
	{
		chr = (char)take_c(args);
		res = make_str(format, chr);
	}
	return (res);
}