/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzabrots <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 16:11:29 by dzabrots          #+#    #+#             */
/*   Updated: 2017/11/23 15:37:11 by dzabrots         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *res;

	if ((res = (t_list *)malloc(sizeof(t_list))))
	{
		if (!content)
		{
			res->content = NULL;
			res->content_size = 0;
		}
		else
		{
			if ((res->content = malloc(content_size)))
			{
				res->content = ft_memcpy(res->content, content, content_size);
				res->content_size = content_size;
			}
			else
				res->content_size = 0;
		}
		res->next = NULL;
	}
	return (res);
}
