#include "../../inc/ft_printf.h"

char			*set_sign(t_format *format, char *arg)
{
	char 		*sign;

	sign = NULL;
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
			{	
				if (!ft_strequ(arg, "0"))
					sign = "0";
			}
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
			ft_memset(str, '0', precision - len);
			ft_strcpy(str + precision - len, num);
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

char			*build_zero_str(size_t width, char *num, char *sign)
{
	char			*str;
	char			*buf;
	size_t			len;

	str = num;
	len = ft_strlen(num);
	if (width > len)
	{
		str = set_free_width(width, 1);
		buf = del_sign(num);
		if (sign)
		{
			ft_memcpy(str, sign, ft_strlen(sign));
			ft_memcpy(str + width - ft_strlen(buf), buf, ft_strlen(buf));
		}
		else
			ft_memcpy(str + width - ft_strlen(buf), buf, ft_strlen(buf));
		free (buf);
		buf = NULL;
	}
	return (str);
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