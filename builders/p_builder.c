#include "../ft_printf.h"

char		*build_p(t_format *format, va_list args)
{
	format->plus = 0;
	format->space = 0;
	format->hash = '#';
	format->zero = 0;
	format->precision = -1;
	format->size = ft_strdup("l");
	format->type = 'x';
	return (build_oux(format, args));
}