/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_builder.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzabrots <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 16:05:03 by dzabrots          #+#    #+#             */
/*   Updated: 2018/05/18 16:05:04 by dzabrots         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

static char	*get_big_s(va_list args)
{
	char	*arg;
	wchar_t *wchr;

	wchr = va_arg(args, wchar_t *);
	if (wchr)
		arg = ft_wstrtostr(wchr);
	else
		arg = ft_strdup("(null)");
	return (arg);
}

char		*build_s(t_format *format, va_list args)
{
	char	*arg;

	if (format->type == 'S' || ft_strequ(format->size, "l"))
		arg = get_big_s(args);
	else
	{
		arg = va_arg(args, char *);
		if (!arg)
			arg = ft_strdup("(null)");
		else
			arg = ft_strdup(arg);
	}
	if (format->precision >= 0)
	{
		if (format->type == 'S' || ft_strequ(format->size, "l"))
		{
			while (arg[format->precision] < -63)
				format->precision--;
		}
		set_precision(&arg, format->precision);
	}
	if (format->width)
		ft_mleak(&arg, set_width(format->minus, format->width, arg));
	return (arg);
}
