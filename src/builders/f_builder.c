#include "../../inc/ft_printf.h"

static char				*f_to_str(t_format *format, long double num)
{
	char				*res;
	
	res = ft_itoa(num);
	if (format->precision == 0)
		return (res);
	else
	{
		
	}
}

static char				*make_f(t_format *format, long double num)
{
	char				*str;

	str = f_to_str(format, num);
}

static long double		take_f(t_format *format, va_list args)
{
	if (format->type == 'F' || ft_strequ(format->size, "L"))
		return (va_arg(args, long double));
	else
		return (va_arg(args, double));
}

void					build_f(t_format *format, va_list args)
{
	long double			num;
	char				*str;

	num = take_f(format, args);
	if (format->precision == -1)
		format->precision = 6;
	str = make_f(format, num);
	//printf("%Lf\n", num);
}