#include "../ft_printf.h"

static char			*make_di(t_format *format, char *arg)
{
	char			*res;
	
	res = set_sign(format, arg);
}

static char			*take_di(t_format *format, va_list args)
{
	if (t_format->type == 'D')
		return (ft_itoa_base((uintmax_t)va_arg(args, long), 10));
	else if (ft_strequ(t_format->size, "hh"))
		return (ft_itoa_base((uintmax_t)va_arg(args, signed char), 10));
	else if (ft_strequ(t_format->size, "h"))
		return (ft_itoa_base((uintmax_t)va_arg(args, short), 10));
	else if (ft_strequ(t_format->size, "l"))
		return (ft_itoa_base((uintmax_t)va_arg(args, long), 10));
	else if (ft_strequ(t_format->size, "ll"))
		return (ft_itoa_base((uintmax_t)va_arg(args, long long), 10));
	else if (ft_strequ(t_format->size, "j"))
		return (ft_itoa_base((uintmax_t)va_arg(args, intmax_t), 10));
	else if (ft_strequ(t_format->size, "z"))
		return (ft_itoa_base((uintmax_t)va_arg(args, size_t), 10));
	else
		return (NULL);
}

char				*build_di(t_format *format, va_list args)
{
	char			*arg;

	arg = get_di(format, args);
	return (make_di(format, arg));
}