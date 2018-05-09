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

int		print_lst(t_list *lst)
{
	int chars;

	if (!lst)
		return (0);
	chars = 0;
	while (lst)
	{
		//printf("c_size: %zu\n", lst->content_size);
		//ft_lstprint(lst);
		//write(1, (char **)&(lst->content), lst->content_size);
		//ft_putendl("\n-------------------------");
		//ft_putstr((char *)lst->content);
		//ft_putendl("\n-------------------------");
		//ft_putchar(((char *)(lst->content))[0]);
		put_content(lst);
		// ft_putnbr((int)lst->content_size);
		chars += ft_strlen((char *)lst->content);
		lst = lst->next;
	}
	return (chars);
}
