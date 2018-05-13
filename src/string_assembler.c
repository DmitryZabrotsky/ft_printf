/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_assembler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzabrots <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 15:14:34 by dzabrots          #+#    #+#             */
/*   Updated: 2018/04/06 15:15:40 by dzabrots         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static int		check_format(t_format *format)
{
	if (format->zero && format->minus)
	{
		format->zero = 0;
		return (1);
	}
	if (format->zero && format->precision >= 0)
	{
		format->zero = 0;
		return (2);
	}
	if (format->space && format->plus)
	{
		format->space = 0;
		return (3);
	}
	return (0);
}

char			*assemble_string(t_format *format, va_list args, t_flags *flags)
{
	check_format(format);
	if (format->type == '%')
		//return ("DZ <3 AC");
		return (build_percent(format));
	else if (format->type == 'c' || format->type == 'C')
		//return ("DZ <3 AC");
		return (build_c(format, args, flags));
	else if (format->type == 's' || format->type == 'S')
		//return ("DZ <3 AC");
		return (build_s(format, args));
	else if (format->type == 'd' || format->type == 'D' || format->type == 'i')
		return ("DZ <3 AC");
		//return (build_di(format, args));
	else if (format->type == 'o' || format->type == 'O' ||
			format->type == 'u' || format->type == 'U' ||
			format->type == 'x' || format->type == 'X')
		return ("DZ <3 AC");
		//return (build_oux(format, args, flags));
	else if (format->type == 'p')
		return ("DZ <3 AC");
		//return (build_p(format, args, flags));
	else if (format->type == 'b')
		return ("DZ <3 AC");
		//return (build_oux(format, args, flags));
	else if (format->type == 'f' || format->type == 'F')
		return ("DZ <3 AC");
		//return (build_f(format, args));
	else if (format->type == 'e' || format->type == 'E')
		return ("DZ <3 AC");
		//return (build_e(format, args));
	else if (format->type == 'a' || format->type == 'A')
		return ("DZ <3 AC");
		//return (build_a(format, args));
	else
		return (ft_strdup("")); //think about this!
}
