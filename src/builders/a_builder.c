/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_builder.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzabrots <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 14:26:37 by dzabrots          #+#    #+#             */
/*   Updated: 2018/05/18 14:26:50 by dzabrots         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

static int		f_to_a(long double *num, t_format *format)
{
	int p;
	int min;
	int max;

	if (*num == 0)
		return (0);
	min = ft_strequ(format->size, "L") ? 8 : 1;
	max = ft_strequ(format->size, "L") ? 16 : 2;
	p = 0;
	while (min > (intmax_t)(*num) || max <= (intmax_t)(*num))
	{
		if ((intmax_t)(*num) < min)
		{
			*num *= 2.0;
			p--;
		}
		if ((intmax_t)(*num) >= max)
		{
			*num /= 2.0;
			p++;
		}
	}
	return (p);
}

static char		*find_exp(int p)
{
	char		*res;

	if (p < 0)
	{
		p *= -1;
		res = ft_itoa(p);
		ft_mleak(&res, ft_strjoin("p-", res));
	}
	else
	{
		res = ft_itoa(p);
		ft_mleak(&res, ft_strjoin("p+", res));
	}
	return (res);
}

static char		*init_a(t_format *format, char **m, char **exp, long double *n)
{
	char *str;

	*m = check_sign(n);
	*exp = find_exp(f_to_a(n, format));
	str = f_to_hexstr(format->precision, *n);
	ft_mleak(&str, ft_strjoin("0x", str));
	ft_mleak(&str, ft_strjoin(str, *exp));
	return (str);
}

static char		*make_a(t_format *format, long double num)
{
	char		*str;
	char		*exp;
	char		*pnum;
	char		*sign;
	char		*minus;

	str = init_a(format, &minus, &exp, &num);
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

char			*build_a(t_format *format, va_list args)
{
	long double	num;
	char		*str;

	if (ft_strequ(format->size, "L"))
		num = va_arg(args, long double);
	else
		num = (long double)va_arg(args, double);
	str = make_a(format, num);
	if (format->type == 'A')
		to_upper(&str);
	return (str);
}
