#include "../../inc/ft_printf.h"

void			to_upper(char **str)
{
	int i;

	i = 0;
	while ((*str)[i])
	{
		if ((*str)[i] >= 'a' && (*str)[i] <= 'z')
			(*str)[i] = (*str)[i] - 32;
		i++;
	}
}

static void			make_oux(t_format *format, char **arg)
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
		{
			if (format->precision == 0 && ft_strequ(*arg, "0") && !format->hash)
				num = ft_strdup("");
			else
				num = set_num_precision(format->precision, *arg);
		}
		if (sign)
			num = ft_strjoin(sign, num);
		if (format->width && !(format->zero))
			num = set_width(format->minus, format->width, num);
	}
	*arg = num;
}

static char			*take_oux(t_format *format, va_list args, int base)
{
	if (format->type == 'U')
		return (ft_itoa_base(va_arg(args, unsigned long), base));
	else if (ft_strequ(format->size, "hh"))
		return (ft_itoa_base((unsigned char)va_arg(args, int), base));
	else if (ft_strequ(format->size, "h"))
		return (ft_itoa_base((unsigned short)va_arg(args, int), base));
	else if (ft_strequ(format->size, "l"))
		return (ft_itoa_base(va_arg(args, unsigned long), base));
	else if (ft_strequ(format->size, "ll"))
		return (ft_itoa_base(va_arg(args, unsigned long long), base));
	else if (ft_strequ(format->size, "j"))
		return (ft_itoa_base(va_arg(args, uintmax_t), base));
	else if (ft_strequ(format->size, "z"))
		return (ft_itoa_base(va_arg(args, size_t), base));
	else
		return(ft_itoa_base(va_arg(args, unsigned int), base));
}

char				*build_oux(t_format *format, va_list args, t_flags *flags)
{
	char			*arg;

	format->space = 0;
	format->plus = 0;
	if (format->type == 'u' || format->type == 'U')
		arg = take_oux(format, args, 10);
	else if (format->type == 'o')
		arg = take_oux(format, args, 8);
	else if (format->type == 'x' || format->type == 'X')
		arg = take_oux(format, args, 16);
	else if (format->type == 'b')
		arg = take_oux(format, args, 2);
	if (format->type == 'x' && ft_strequ(arg, "0")
		&& format->hash && !flags->p)
		format->hash = 0;
	make_oux(format, &arg);
	flags->p = 0;
	if (format->type == 'X')
		to_upper(&arg);
	return (arg);
}