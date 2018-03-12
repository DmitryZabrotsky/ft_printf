#include "../ft_printf.h"

char		*set_width(int minus, size_t width, char *arg)
{
	char	*str;
	size_t	len;

	len = ft_strlen(arg);
	if (width > len)
	{	
		if ((str = ft_strnew(width)))
		{
			if (minus)
			{
				ft_strcpy(str, arg);
				ft_memset(str + len, ' ', width - len);
			}
			else
			{
				ft_memset(str, ' ', width - len);
				ft_strcpy(str + width - len, arg);
			}
			return (str);
		}
	}
	return (arg);
}

void		set_precision(char **str, size_t precision)
{
	size_t	len;
	size_t	del;

	len = ft_strlen(*str);
	if (precision == 0)
		ft_memset(*str, '\0', len);
	else if (len > precision)
	{
		del = len - precision;
		ft_memset(*str + precision, '\0', del);
	}
}