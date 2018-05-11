#include "../../inc/ft_printf.h"

char *build_percent(t_format *format)
{
	char *res;

	res = ft_strdup("%");
	if (format->width)
		ft_mleak(&res, set_width(format->minus, format->width, res));
	return (res);
}