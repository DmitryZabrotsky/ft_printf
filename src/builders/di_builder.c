/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   di_builder.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzabrots <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 15:00:41 by dzabrots          #+#    #+#             */
/*   Updated: 2018/05/18 15:00:44 by dzabrots         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

static char			*make_di(t_format *format, char **arg, int zeroformat)
{
	char			*num;
	char			*sign;

	num = del_sign(*arg);
	sign = set_sign(format, *arg);
	if (format->precision >= 0)
	{
		if (format->precision == 0 && !(ft_strcmp(*arg, "0")))
			ft_mleak(&num, ft_strdup(""));
		else
			ft_mleak(&num, set_num_precision(format->precision, *arg));
	}
	if (format->zero && format->width)
	{
		ft_mleak(&num, build_zero_str(format->width, num, sign));
		zeroformat = 1;
		if (sign && !ft_strequ(sign, "-") && num[0] != '+' && num[0] != ' ')
			ft_mleak(&num, ft_strjoin(sign, num));
	}
	if (sign && !zeroformat)
		ft_mleak(&num, ft_strjoin(sign, num));
	if (format->width && !(format->zero))
		ft_mleak(&num, set_width(format->minus, format->width, num));
	return (num);
}

static char			*take_di(t_format *format, va_list args)
{
	if (format->type == 'D')
		return (ft_itoa(va_arg(args, long)));
	if (format->type == 'd' || format->type == 'i')
	{
		if (format->size)
		{
			if (ft_strequ(format->size, "hh"))
				return (ft_itoa((signed char)va_arg(args, int)));
			else if (ft_strequ(format->size, "h"))
				return (ft_itoa((short)va_arg(args, int)));
			else if (ft_strequ(format->size, "l"))
				return (ft_itoa(va_arg(args, long)));
			else if (ft_strequ(format->size, "ll"))
				return (ft_itoa(va_arg(args, long long)));
			else if (ft_strequ(format->size, "j"))
				return (ft_itoa(va_arg(args, intmax_t)));
			else if (ft_strequ(format->size, "z"))
				return (ft_itoa(va_arg(args, size_t)));
		}
		return (ft_itoa(va_arg(args, int)));
	}
	else
		return (NULL);
}

char				*build_di(t_format *format, va_list args)
{
	char			*arg;
	char			*res;

	arg = take_di(format, args);
	res = make_di(format, &arg, 0);
	free(arg);
	return (res);
}
