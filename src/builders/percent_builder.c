/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_builder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzabrots <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 16:04:29 by dzabrots          #+#    #+#             */
/*   Updated: 2018/05/18 16:04:32 by dzabrots         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

char		*build_percent(t_format *format)
{
	char	*res;

	res = ft_strdup("%");
	if (format->width)
		ft_mleak(&res, set_width(format->minus, format->width, res));
	return (res);
}
