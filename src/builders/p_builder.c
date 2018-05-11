#include "../../inc/ft_printf.h"

char		*build_p(t_format *format, va_list args, t_flags *flags)
{
	flags->p = 1;
	format->plus = 0;
	format->space = 0;
	format->hash = '#';
	format->zero = 0;
	format->precision = -1;
	format->size = ft_strdup("l");
	format->type = 'x';
	return (build_oux(format, args, flags));
}