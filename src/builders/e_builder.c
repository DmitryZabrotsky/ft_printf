/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_builder.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzabrots <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 14:55:26 by dzabrots          #+#    #+#             */
/*   Updated: 2018/05/18 14:55:29 by dzabrots         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

static int				f_to_e(long double *num)
{
	int					e;

	if (*num == 0)
		return (0);
	e = 0;
	while (1.0 > *num || 10.0 <= *num)
	{
		if (*num < 1.0)
		{
			*num *= 10.0;
			e--;
		}
		if (*num >= 10.0)
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

static void				free_make_e(char *exp, char *str)
{
	free(exp);
	free(str);
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
	free_make_e(exp, str);
	return (pnum);
}

char					*build_e(t_format *format, va_list args)
{
	long double			num;
	char				*str;

	if (ft_strequ(format->size, "L"))
		num = (long double)va_arg(args, long double);
	else
		num = (long double)va_arg(args, double);
	if (format->precision == -1)
		format->precision = 6;
	str = make_e(format, num);
	if (format->type == 'E')
		to_upper(&str);
	return (str);
}
