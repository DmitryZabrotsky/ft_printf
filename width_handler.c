#include "ft_printf.h"

int		handle_width(const char *fstr, t_format *format, va_list args)
{
	int i;

	i = 0;
	if (fstr[i] == '*')
	{
		format->width = va_arg(args, int);
		i++;
	}
	else
	{
		while (fstr[i] && fstr[i] != '.' && ft_isdigit(fstr[i]))
			i++; 
	}
	format->width = ft_atoi(fstr);
	return (i);
}