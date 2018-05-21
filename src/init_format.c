/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_format.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzabrots <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 15:04:10 by dzabrots          #+#    #+#             */
/*   Updated: 2018/05/18 13:31:05 by dzabrots         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

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

void				free_format(t_format **format)
{
	if ((*format)->size)
		free((*format)->size);
	free(*format);
	*format = NULL;
}

t_flags				*init_flags(void)
{
	t_flags			*ret;

	if ((ret = (t_flags *)malloc(sizeof(t_format))))
	{
		ret->cnull = 0;
		ret->p = 0;
		ret->error = 0;
		ret->chr = '\0';
		ret->minuscnull = 0;
		ret->len = 0;
		ret->n = 0;
		ret->color = NULL;
	}
	return (ret);
}

void				free_flags(t_flags **flags)
{
	free(*flags);
	*flags = NULL;
}
