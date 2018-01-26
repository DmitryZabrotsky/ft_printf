/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsttoarr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzabrots <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 14:28:11 by dzabrots          #+#    #+#             */
/*   Updated: 2017/11/30 16:54:21 by dzabrots         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_lsttoarr(t_list *lst)
{
	char	**arr;
	size_t	lst_len;

	lst_len = ft_lstlen(lst);
	if (!(arr = (char **)malloc(sizeof(char *) * lst_len)))
		return (NULL);
	while (lst)
	{
		*arr = (char *)malloc(sizeof(char) * lst->content_size + 1);
		*arr = ft_strdup(lst->content);
		arr++;
		lst = lst->next;
	}
	return (arr - lst_len);
}
