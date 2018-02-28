#include "ft_printf.h"

int		handle_format(const char *fstr, va_list args)
{
	int i;
	t_format *format;

	i = 0;
	format = init_format();
	ft_putendl(fstr);
	//while (fstr[i])
	//{
		if (fstr[i] == '%')
		{
			ft_putendl(fstr);
			i++;
			ft_putstr("% WAS FINDED");
		}
		else
		{
			i += handle_flags(fstr + i, format);
			i += handle_width(fstr + i, format, args);
		}
	//}
	print_format(format);
	return (i);
}	