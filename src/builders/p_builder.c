/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_builder.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzabrots <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 16:04:01 by dzabrots          #+#    #+#             */
/*   Updated: 2018/05/18 16:04:03 by dzabrots         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

char		*build_p(t_format *format, va_list args, t_flags *flags)
{
	flags->p = 1;
	format->plus = 0;
	format->space = 0;
	format->hash = '#';
	format->zero = 0;
	format->precision = -1;
	format->size = ft_strdup("l");
	format->type = 'x';
	return (build_oux(format, args, flags));
}
