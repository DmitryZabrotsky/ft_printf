#include "ft_printf.h"

int		handle_format(const char *fstr, va_list args, t_list **lst)
{
	int i;
	t_format *format;

	i = 0;
	format = init_format();
	while (fstr[i])
	{
		if (fstr[i] == '%')
		{
			i++;
			ft_putstr("%");
		}
		else
		{
			i += handle_flags(fstr, );
			i += handle_width();
		}
	}
	print_format(format);
	return (i);
}