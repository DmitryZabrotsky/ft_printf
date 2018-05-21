/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzabrots <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 16:50:58 by dzabrots          #+#    #+#             */
/*   Updated: 2018/05/18 16:51:20 by dzabrots         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

int			handle_size(const char *fstr, t_format *format)
{
	if (ft_strnequ(fstr, "hh", 2))
		format->size = ft_strdup("hh");
	else if (ft_strnequ(fstr, "h", 1))
		format->size = ft_strdup("h");
	else if (ft_strnequ(fstr, "ll", 2))
		format->size = ft_strdup("ll");
	else if (ft_strnequ(fstr, "l", 1))
		format->size = ft_strdup("l");
	else if (ft_strnequ(fstr, "L", 1))
		format->size = ft_strdup("L");
	else if (ft_strnequ(fstr, "j", 1))
		format->size = ft_strdup("j");
	else if (ft_strnequ(fstr, "z", 1))
		format->size = ft_strdup("z");
	return ((int)ft_strlen(format->size));
}
