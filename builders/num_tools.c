#include "../ft_print.h"

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
			if (format->type == 'o' || foramt->type == 'O')
				sign = "0";
			else if (format->type == 'x' || format->type == 'X')
				sign = "0x";
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
	if (precision > 0 && precision > len)
	{
		if ((str = ft_strnew(precision)))
		{
			ft_strcpy(str + len, num);
			ft_memset(str, '0', str - len);
			free(num)
			return (str); 
		}
	}
	return (num);
}