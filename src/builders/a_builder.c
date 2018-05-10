#include "../../inc/ft_printf.h"

static int f_to_a(long double *num, t_format *format)
{
	(void)format;
	if (*num == 0)
		return (0);
	return (1);
	// int p;
	// int min;
	// int max;

	// if (*num == 0)
	// 	return (0);
	// min = ft_strequ(format->size, "L") ? 8 : 1;
	// max = ft_strequ(format->size, "L") ? 16 : 2;
	// p = 0;
	// while (min > (intmax_t)(*num) || max <= (intmax_t)(*num))
	// {
	// 	if ((intmax_t)(*num) < min)
	// 	{
	// 		*num *= 2;
	// 		p--;
	// 	}
	// 	if ((intmax_t)(*num) >= max)
	// 	{
	// 		*num /= 2;
	// 		p++;
	// 	}
	// }
	// return (p);
}

static char				*find_exp(int p)
{
	char				*res;

	if (p < 0)
	{
		p *= -1;
		res = ft_itoa(p);
		if (p < 10)
			ft_mleak(&res, ft_strjoin("p-", res));
		else
			ft_mleak(&res, ft_strjoin("p-", res));
	}
	else
	{
		res = ft_itoa(p);
		ft_mleak(&res, ft_strjoin("p+", res)); 
	}
	return (res);
}

static char				*make_a(t_format *format, long double num)
{
	char				*str;
	char				*exp;
	char				*pnum;
	char				*sign;
	char				*minus;

	minus = check_sign(&num);
	exp = find_exp(f_to_a(&num, format));
	str = f_to_hexstr(format->precision, num);
	ft_mleak(&str, ft_strjoin("0x", str));
	ft_mleak(&str, ft_strjoin(str, exp));
	if (minus)
		ft_mleak(&str, ft_strjoin(minus, str));
	pnum = del_sign(str);
	sign = set_sign(format, str);
	if (format->zero && format->width)
		ft_mleak(&pnum, build_zero_str(format->width, str, sign));
	else
	{
		if (sign)
			ft_mleak(&pnum, ft_strjoin(sign, pnum));
		if (format->width && !(format->zero))
			ft_mleak(&pnum, set_width(format->minus, format->width, pnum));
	}
	free(exp);
	free(str);
	return (pnum);
}

static long double		take_a(t_format *format, va_list args)
{
	if (ft_strequ(format->size, "L"))
		return (va_arg(args, long double));
	else
		return ((long double)va_arg(args, double));
}

char					*build_a(t_format *format, va_list args)
{
	long double			num;
	char				*str;

	num = take_a(format, args);
	str = make_a(format, num);
	if (format->type == 'A')
		to_upper(&str);
	return (str);
}