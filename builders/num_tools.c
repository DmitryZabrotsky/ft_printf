#include "../ft_printf.h"

char			*set_sign(t_format *format, char *arg)
{
	char 		*sign;

	sign = 0;
	if (*arg == '-')
		sign = "-";
	else
	{
		if (format->space)
			sign = " ";
		else if (format->plus)
			sign = "+";
		else if (format->hash)
		{	
			if (format->type == 'o' || format->type == 'O')
				sign = "0";
			else if (format->type == 'x' || format->type == 'X')
				sign = "0x";
		}
	}
	return (sign);
}

char			*set_num_precision(int precision, char *arg)
{
	char		*num;
	char		*str;
	size_t		len;

	if (*arg == '-')
		num = ft_strdup(arg + 1);
	else
		num = ft_strdup(arg);
	len = ft_strlen(num);
	if (precision > 0 && (size_t)precision > len)
	{
		if ((str = ft_strnew(precision)))
		{
			ft_strcpy(str + len, num);
			ft_memset(str, '0', precision - len);
			free(num);
			num = NULL;
			return (str); 
		}
	}
	return (num);
}

char			*set_free_width(size_t width, int zero)
{
	char		*str;

	str = ft_strnew(width);
	if (zero)
		ft_memset(str, '0', width);
	else		
		ft_memset(str, ' ', width);
	return(str);
}

char			*del_sign(char *arg)
{
	char		*num;

	if (*arg == '-')
		num = ft_strdup(arg + 1);
	else
		num = ft_strdup(arg);
	return (num);
}