#include "../../inc/ft_printf.h"

int		handle_format(const char *fstr, t_list **lst, va_list args)
{
	int i;
	char *str;
	t_format *format;

	i = 0;
	format = init_format();
	if (fstr[i] == '%')
	{
		i++;
		str = ft_strdup("%");
	}
	else
	{
		i += handle_flags(fstr + i, format);
		i += handle_width(fstr + i, format, args);
		i += handle_precision(fstr + i, format, args);
		i += handle_size(fstr + i, format);
		i += handle_type(fstr +i, format);
		str = assemble_string(format, args);
	}
//print_format(format);
	ft_lstaddend(lst, ft_lstnew(str, ft_strlen(str) + 1));
	free(str);
	free_format(&format);
	return (i);
}	