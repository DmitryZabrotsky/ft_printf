#include "../../inc/ft_printf.h"

char				*f_to_str(int prec, long double num)
{
	char *str;
	char *dot;
	int i;

	str = ft_itoa(num);
	if (prec > 0)
	{	
		str = ft_strjoin(str, ".");
		dot = ft_strnew(prec);
		rounder(prec, &num);
		// if (prec <= 6)
		// 	num += 1e-9;
		i = 0;
		while (prec > 0)
		{
			num -= (intmax_t)num;
			num *= (long double)10.0;
			dot[i] = '0' + (intmax_t)num;
			i++;
			prec--;
		}
		dot[i] = '\0';
		str = ft_strjoin(str, dot);
	}
	return (str);
}

static char				*make_f(t_format *format, long double num)
{
	char				*str;
	char				*pnum;
	char				*sign;
	char				*minus;

	minus = check_sign(&num);
	str = f_to_str(format->precision, num);
	if (minus)
		str = ft_strjoin(minus, str);
	pnum = del_sign(str);
	sign = set_sign(format, str);
	if (format->zero && format->width)
		pnum = build_zero_str(format->width, str, sign);
	else
	{
		if (sign)
			pnum = ft_strjoin(sign, pnum);
		if (format->width && !(format->zero))
			pnum = set_width(format->minus, format->width, pnum);
	}
	return (pnum);
}

static long double		take_f(t_format *format, va_list args)
{
	if (ft_strequ(format->size, "L"))
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