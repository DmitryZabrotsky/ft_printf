/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzabrots <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 16:31:44 by dzabrots          #+#    #+#             */
/*   Updated: 2018/05/18 16:31:46 by dzabrots         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

static int		handle_flag(const char fchr, t_format *format)
{
	if (fchr == '-')
		return (format->minus = 1);
	if (fchr == '+')
		return (format->plus = 1);
	if (fchr == ' ')
		return (format->space = 1);
	if (fchr == '#')
		return (format->hash = 1);
	if (fchr == '0')
		return (format->zero = 1);
	return (0);
}

int				handle_flags(const char *fstr, t_format *format)
{
	int			i;

	i = 0;
	while (handle_flag(fstr[i], format))
		i++;
	return (i);
}
