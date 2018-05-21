/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzabrots <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 16:12:31 by dzabrots          #+#    #+#             */
/*   Updated: 2018/05/18 16:12:33 by dzabrots         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

void		rounder(int prec, long double *num)
{
	long double number;
	int			i;
	int			ten;

	number = *num;
	i = 0;
	ten = 1;
	while (i < prec)
	{
		number *= 10;
		number -= (intmax_t)number;
		i++;
		ten *= 10;
	}
	if (number - (intmax_t)number < 0.5)
	{
		ten *= 10;
		*num += 1.0 / ten;
	}
	else
		*num += 1.0 / ten;
}

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
	return (ft_strdup(arg));
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
