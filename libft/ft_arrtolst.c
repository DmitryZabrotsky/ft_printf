/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrtolst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzabrots <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 19:50:11 by dzabrots          #+#    #+#             */
/*   Updated: 2017/11/27 19:50:25 by dzabrots         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_arrtolst(char **arr)
{
	t_list *lst;

	if (*arr)
	{
		lst = ft_lstnew((void const *)*arr,
				sizeof(char) * (ft_strlen(*arr) + 1));
		lst->next = ft_arrtolst(++arr);
		return (lst);
	}
	return (NULL);
}
