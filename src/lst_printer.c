/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_printer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzabrots <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 15:15:53 by dzabrots          #+#    #+#             */
/*   Updated: 2018/04/06 15:16:05 by dzabrots         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int		print_lst(t_list *lst)
{
	int chars;

	if (!lst)
		return (0);
	chars = 0;
	while (lst)
	{
		ft_putstr((char *)lst->content);
		chars += ft_strlen((char *)lst->content);
		lst = lst->next;
	}
	return (chars);
}
