#include "ft_printf.h"
#include <stdio.h>
#include <stdlib.h>

static t_flags		*init_flags(void)
{
	t_flags 		*ret;
	
	if ((ret = (t_flags *)malloc(sizeof(t_flags))))
	{
		ret->minus = 0;
		ret->plus = 0;
		ret->space = 0;
		ret->hash = 0;
		ret->zero = 0;
	}
	return (ret);
}

t_format			*init_format(void)
{
	t_format 		*ret;
	
	if ((ret = (t_format *)malloc(sizeof(t_format))))
	{
		ret->flags = init_flags();
		ret->width = 0;
		ret->precision = 0;
		ret->type = 0;
		ret->conversion = '\0';
	}
	return (ret);
}

void 		print_format(t_format *format)
{
	printf("FLAGS:\nminus: %d\nplus: %d\nspace: %d\nhash: %d\nzero: %d\n\nFORMAT:\nwidth: %d\nprecision: %d\ntype: %s\nconversion: %c\n", format->flags->minus, format->flags->plus, 
	format->flags->space, format->flags->hash, format->flags->zero, format->width, 
	format->precision, format->type, format->conversion);
}
