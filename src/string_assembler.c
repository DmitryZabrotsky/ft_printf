#include "../inc/ft_printf.h"

static int		check_format(t_format *format)
{
	if (format->zero && format->minus)
	{
		format->zero = 0;
		return (1);
	}
	if (format->zero && format->precision >= 0)
	{
		format->zero = 0;
		return (2);
	}
	if (format->space && format->plus)
	{
		format->space = 0;
		return (3);
	}
	return (0);
}

char			*assemble_string(t_format *format, va_list args)
{
	check_format(format);
	if (format->type == 'c' || format->type == 'C')
		return (build_c(format, args));
	else if (format->type == 's' || format->type == 'S')
		return (build_s(format, args));
	else if (format->type == 'd' || format-> type == 'D' || format->type == 'i')
		return (build_di(format, args));
	else if (format->type == 'o' || format->type == 'u' || format->type == 'U'
		|| format->type == 'x' || format->type == 'X')
		return (build_oux(format, args));
	else if (format->type == 'p')
		return (build_p(format, args));
	else if (format->type == 'b')
		return (build_oux(format, args));
	else if (format->type == 'f' || format->type == 'F')
	{
		build_f(format, args);
		return(ft_strdup("FLOAT INDA HOUSE!"));
	}
	else
		return (NULL);
}