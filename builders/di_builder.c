#include "../ft_printf.h"

static void			build_zero_str(size_t width, char **num, char *sign)
{
	char			*str;
	char			*buf;

	str = set_free_width(width, 1);
	buf = del_sign(*num);
	if (sign)
	{
		ft_strcpy(str, sign);
		ft_strcpy(str + width - ft_strlen(*num), buf);
	}
	else
		ft_strcpy(str + width - ft_strlen(*num), *num);
	*num = str;
	free (str);
	str = NULL;
	free (buf);
	buf = NULL;
}

static void			make_di(t_format *format, char **arg)
{
	char			*num;
	char			*sign;

	num = *arg;
	sign = set_sign(format, *arg);
	if (format->zero && format->width)
		build_zero_str(format->width, &num, sign);
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
	free (num);
	num = NULL;
}

static char			*take_di(t_format *format, va_list args)
{
	if (format->type == 'D')
		return (ft_itoa_base(va_arg(args, long), 10));
	if (format->type == 'd' || format->type == 'i')
	{
		if (format->size)
		{
			if (ft_strequ(format->size, "hh"))
				return (ft_itoa_base((int)va_arg(args, int), 10));
			else if (ft_strequ(format->size, "h"))
				return (ft_itoa_base((int)va_arg(args, int), 10));
			else if (ft_strequ(format->size, "l"))
				return (ft_itoa_base(va_arg(args, long), 10));
			else if (ft_strequ(format->size, "ll"))
				return (ft_itoa_base(va_arg(args, long long), 10));
			else if (ft_strequ(format->size, "j"))
				return (ft_itoa_base(va_arg(args, intmax_t), 10));
			else if (ft_strequ(format->size, "z"))
				return (ft_itoa_base(va_arg(args, size_t), 10));
		}
		return (ft_itoa_base(va_arg(args, int), 10));
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