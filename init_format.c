#include "ft_printf.h"
#include <stdio.h>
#include <stdlib.h>

t_format			*init_format(void)
{
	t_format 		*ret;
	
	if ((ret = (t_format *)malloc(sizeof(t_format))))
	{
		ret->minus = 0;
		ret->plus = 0;
		ret->space = 0;
		ret->hash = 0;
		ret->zero = 0;
		ret->width = 0;
		ret->precision = 0;
		ret->type = 0;
		ret->conversion = '\0';
	}
	return (ret);
}

void 		print_format(t_format *format)
{
	printf(" -----> FLAGS:\nminus: %d\nplus: %d\nspace: %d\nhash: %d\nzero: %d\n\n ----> FORMAT:\nwidth: %d\nprecision: %d\ntype: %s\nconversion: %c\n", format->minus, format->plus, 
	format->space, format->hash, format->zero, format->width, 
	format->precision, format->type, format->conversion);
}

void	free_format(t_format **format)
{
	free(*format);
	*format = NULL;
}
