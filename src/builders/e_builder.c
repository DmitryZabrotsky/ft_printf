#include "../../inc/ft_printf.h"

static int				f_to_e(long double *num)
{
	int					e;

	if (*num == 0)
		return (0);
	//return (1);
	e = 0;
	while (1 > (intmax_t)(*num) || 10 <= (intmax_t)(*num))
	{
		if ((intmax_t)(*num) < 1)
		{
			*num *= 10.0;
			e--;
		}
		if ((intmax_t)(*num) >= 10)
		{
			*num /= 10.0;
			e++;
		}
	}
	return (e);
}

static char				*find_exp(int e)
{
	char				*res;

	if (e < 0)
	{
		e *= -1;
		res = ft_itoa(e);
		if (e < 10)
		{	
			ft_mleak(&res, ft_strjoin("0", res));
			ft_mleak(&res, ft_strjoin("e-", res));
		}
		else
			ft_mleak(&res, ft_strjoin("e-", res));
	}
	else
	{
		res = ft_itoa(e);
		if (e < 10)
			ft_mleak(&res, ft_strjoin("e+0", res));
		else
			ft_mleak(&res, ft_strjoin("e+", res)); 
	}
	return (res);
}

static char				*make_e(t_format *format, long double num)
{
	char				*str;
	char				*exp;
	char				*pnum;
	char				*sign;
	char				*minus;

	minus = check_sign(&num);
	exp = find_exp(f_to_e(&num));
	str = f_to_str(format->precision, num);
	str = ft_strjoin(str, exp);
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

static long double		take_e(t_format *format, va_list args)
{
	if (ft_strequ(format->size, "L"))
		return (va_arg(args, long double));
	else
		return ((long double)va_arg(args, double));
}

char					*build_e(t_format *format, va_list args)
{
	long double			num;
	char				*str;

	num = take_e(format, args);
	if (format->precision == -1)
		format->precision = 6;
	str = make_e(format, num);
	if (format->type == 'E')
		to_upper(&str);
	return (str);
}