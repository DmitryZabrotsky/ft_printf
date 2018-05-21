/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzabrots <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 16:52:21 by dzabrots          #+#    #+#             */
/*   Updated: 2018/05/18 16:52:22 by dzabrots         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

int			handle_type(const char *fstr, t_format *format, t_flags *flags)
{
	char *types;

	types = ft_strdup("cCsSdDioOuUxXpbfFeEaAnt%");
	if (fstr[0])
	{
		format->type = fstr[0];
		if (!ft_strchr(types, format->type))
		{
			flags->error = 1;
			flags->chr = format->type;
		}
		free(types);
		return (1);
	}
	else
		return (0);
}
