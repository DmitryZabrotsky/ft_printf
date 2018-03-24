#include "../../inc/ft_printf.h"

static char				*f_to_str(int prec, long double num)
{
	char *str;
	char *dot;
	int i;

	str = ft_itoa(num);
	if (prec > 0)
	{	
		str = ft_strjoin(str, ".");
		dot = ft_strnew(prec);
		if (prec <= 6)
			num += 1e-9;
		i = 0;
		while (prec > 0)
		{
			num -= (int)num;
			num *= 10;
			dot[i] = '0' + (int)num;
			i++;
			prec--;
		}
		str = ft_strjoin(str, dot);
	}
	return (str);
}

static char				*make_f(t_format *format, long double num)
{
	char				*str;

	str = f_to_str(format->precision, num);
	return (str);
}

static long double		take_f(t_format *format, va_list args)
{
	if (format->type == 'F' || ft_strequ(format->size, "L"))
		return (va_arg(args, long double));
	else
		return ((long double)va_arg(args, double));
}

char					*build_f(t_format *format, va_list args)
{
	long double			num;
	char				*str;

	num = take_f(format, args);
	if (format->precision == -1)
		format->precision = 6;
	str = make_f(format, num);
	return (str);
}