#include <stdio.h>
#include <stdarg.h>
#include "./libft/libft.h"

int		count_specs(char *specs)
{
	int i;
	int res;

	i = 0;
	res = 0;

	while (specs[i])
	{
		if (specs[i] == '%')
			res++;
		i++;
	}
	return (res);
}

int		func(char *format, ...)
{
	va_list args;
	char *arg;
	int specs_value;
	int res;

	va_start(args, format);
	specs_value = count_specs(format);
		//printf("%i", specs_value);
	res = 0;
	while (specs_value > 0)
	{
		arg = va_arg(args, char *);
		ft_putstr(arg);
		ft_putchar('\n');
		printf("arg len: %zu res: %i\n", ft_strlen(arg), res);
		res += ft_strlen(arg);
		specs_value--;
	}
	return(res);
}

int		main(void)
{
	ft_putnbr(func("%%%%%", "1", "2", "3", "4", "5"));
}	
