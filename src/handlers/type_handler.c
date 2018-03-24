#include "../../inc/ft_printf.h"

int			handle_type(const char *fstr, t_format *format)
{
	if (fstr[0])
	{
		format->type = fstr[0];
		return (1);
	}
	else
		return (0);
}