/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzabrots <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 15:32:54 by dzabrots          #+#    #+#             */
/*   Updated: 2017/11/23 15:43:12 by dzabrots         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstprint(t_list *lst)
{
	if (!lst)
		return ;
	ft_putendl("----------");
	ft_putstr("content: ");
	if (lst->content)
		ft_putendl((char *)lst->content);
	ft_putstr("content size: ");
	ft_putnbr(lst->content_size);
	ft_putchar('\n');
	if (lst->next)
		ft_putendl("next: exist");
	else
		ft_putendl("next: does not exist");
	ft_putendl("----------");
}
