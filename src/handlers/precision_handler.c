/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzabrots <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 16:50:13 by dzabrots          #+#    #+#             */
/*   Updated: 2018/05/18 16:50:15 by dzabrots         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

int			handle_precision(const char *fstr, t_format *format, va_list args)
{
	int		i;

	i = 0;
	if (fstr[i] == '.')
	{
		i++;
		if (fstr[i] == '*')
		{
			i++;
			format->precision = va_arg(args, int);
		}
		else
		{
			while (ft_isdigit(fstr[i]))
			{
				i++;
			}
			format->precision = ft_atoi(fstr + 1);
		}
	}
	return (i);
}
