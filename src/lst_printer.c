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

void	put_content(t_list *lst)
{
	char *str;
	size_t i;

	i = 0;
	str = (char *)lst->content;
	while (i != lst->content_size - 1)
	{
		ft_putchar(str[i]);
		i++;
	}
}

int		print_lst(t_list *lst, t_flags *flags)
{
	int chars;

	if (!lst)
		return (0);
	chars = 0;
	while (lst)
	{
		put_content(lst);
		if (flags->minuscnull)
		{
			chars += flags->len;
		 	flags->minuscnull = 0;
		 	flags->len = 0;
		}
		else
		{
			chars += ft_strlen((char *)lst->content);
			chars += flags->cnull;
			flags->cnull = 0;
		}
		lst = lst->next;
	}
	return (chars);
}
