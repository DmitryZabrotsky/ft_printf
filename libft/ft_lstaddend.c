/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzabrots <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 21:26:53 by dzabrots          #+#    #+#             */
/*   Updated: 2017/11/24 21:43:41 by dzabrots         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstaddend(t_list **lst, t_list *elem)
{
	t_list *buf;

	if (!lst || !elem)
		return ;
	if (!*lst)
		*lst = elem;
	else
	{
		buf = *lst;
		while (buf->next)
			buf = buf->next;
		buf->next = elem;
	}
}
