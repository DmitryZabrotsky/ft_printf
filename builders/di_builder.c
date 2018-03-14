#include "../ft_printf.h"

static char			*build_zero_str(size_t width, char *num, char *sign)
{
	char			*str;
	char			*buf;

	str = set_free_width(width, 1);
	buf = del_sign(num);
	if (sign)
	{
		ft_memcpy(str, sign, ft_strlen(sign));
		ft_memcpy(str + width - ft_strlen(buf), buf, ft_strlen(buf));
	}
	else
		ft_memcpy(str + width - ft_strlen(buf), buf, ft_strlen(buf));
	free (buf);
	buf = NULL;
	return (str);
}

static void			make_di(t_format *format, char **arg)
{
	char			*num;
	char			*sign;

	num = del_sign(*arg);
	sign = set_sign(format, *arg);
	if (format->zero && format->width)
		num = build_zero_str(format->width, *arg, sign);
	else
	{
		if (format->precision >= 0)
			num = set_num_precision(format->precision, *arg);
		if (sign)
			num = ft_strjoin(sign, num);
		if (format->width && !(format->zero))
			num = set_width(format->minus, format->width, num);
	}
	*arg = num;
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

	arg = take_di(format, args);
	make_di(format, &arg);
	return (arg);
}