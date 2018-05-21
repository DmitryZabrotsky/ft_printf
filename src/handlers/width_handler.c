/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzabrots <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 16:52:41 by dzabrots          #+#    #+#             */
/*   Updated: 2018/05/18 16:52:43 by dzabrots         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

static void		minus_zero_case(int width, t_format *format)
{
	format->width = width * -1;
	if (!format->minus)
		format->minus = 1;
}

int				handle_width(const char *fstr, t_format *format, va_list args)
{
	int			i;
	int			width;

	i = 0;
	if (fstr[i] == '*')
	{
		width = va_arg(args, int);
		i++;
	}
	else
	{
		while (ft_isdigit(fstr[i]))
			i++;
		width = ft_atoi(fstr);
	}
	if (width < 0)
		minus_zero_case(width, format);
	else
		format->width = width;
	if (fstr[i] == '*' || ft_isdigit(fstr[i]))
		return (i + handle_width(fstr + i, format, args));
	return (i);
}
