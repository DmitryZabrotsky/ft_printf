#include "../ft_print.h"

static unsigned char		take_c(t_format *format, va_list args)
{
	//if (ft_strnequ(t_format->size, "l", 1))
	//	take_C(t_format *format, va_list args);
	//else
	return ((unsigned char)va_arg(int));
}
/*
static wchar_t		take_C(t_format *format, va_list args)
{
	return ((wchar_t)va_arg(int));
}
*/
static char			*make_str(t_format *format, char chr)
{
	if (t_format->width)
	{
		//create str size of width
		if (t_format->minus)
			//cpy chr at the start of str
	}
}

char			*build_c(t_format *format, va_list args)
{
	char		chr;
	//wchar_t		wchr;

	if (format->type == 'c')
		chr = take_c(t_format *format, va_list args);
	//else if (format->type == 'C')
	//	wchr = take_C(t_format *format, va_list args);
	return (make_str(format, chr));
}