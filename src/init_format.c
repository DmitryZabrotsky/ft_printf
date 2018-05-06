/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_format.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzabrots <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 15:04:10 by dzabrots          #+#    #+#             */
/*   Updated: 2018/04/06 15:14:15 by dzabrots         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"
#include <stdio.h>
#include <stdlib.h>

t_format			*init_format(void)
{
	t_format		*ret;

	if ((ret = (t_format *)malloc(sizeof(t_format))))
	{
		ret->minus = 0;
		ret->plus = 0;
		ret->space = 0;
		ret->hash = 0;
		ret->zero = 0;
		ret->width = 0;
		ret->precision = -1;
		ret->size = 0;
		ret->type = '\0';
	}
	return (ret);
}

void 				print_format(t_format *format)
{
	printf("\n--- FLAGS:       --- FORMAT:\nminus: %-10dwidth: %-10d\nplus: %-10d precision: %-10d\nspace: %-10dsize: %-10s\nhash: %-10d type: %-10c\nzero: %-10d\n\n",
	format->minus, format->width,
	format->plus, format->precision,
	format->space, format->size,
	format->hash, format->type, 
	format->zero);
}

void				free_format(t_format **format)
{
	if ((*format)->size)
		free((*format)->size);
	free(*format);
	*format = NULL;
}