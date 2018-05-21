/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_builder.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzabrots <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 15:58:49 by dzabrots          #+#    #+#             */
/*   Updated: 2018/05/18 15:58:52 by dzabrots         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

char		*build_n(va_list args, t_flags *flags, t_list *lst)
{
	int		*box;
	t_list	*buf;

	buf = lst;
	flags->n = 1;
	box = (int *)va_arg(args, int *);
	*box = print_lst(buf, flags);
	flags->n = 0;
	return (ft_strdup(""));
}
