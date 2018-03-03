#include "../ft_printf.h"

static unsigned char		take_c(va_list args)
{
	//if (ft_strnequ(t_format->size, "l", 1))
	//	take_C(t_format *format, va_list args);
	//else
	return ((unsigned char)va_arg(args, int));
}
/*
static wchar_t		take_C(t_format *format, va_list args)
{
	return ((wchar_t)va_arg(int));
}
*/
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

char						*build_c(t_format *format, va_list args)
{
	char					chr;
	//wchar_t		wchr;
	chr = '\0';
	if (format->type == 'c')
		chr = (char)take_c(args);
	//else if (format->type == 'C')
	//	wchr = take_C(t_format *format, va_list args);
	return (make_str(format, chr));
}