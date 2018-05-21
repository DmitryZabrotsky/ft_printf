/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_builder.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzabrots <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 16:11:26 by dzabrots          #+#    #+#             */
/*   Updated: 2018/05/18 16:11:28 by dzabrots         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

char		*build_t(va_list args)
{
	char	*res;
	char	*size;
	t_list	*lst;

	lst = (t_list *)(va_arg(args, t_list *));
	res = ft_strdup((char *)lst->content);
	ft_mleak(&res, ft_strjoin(res, " "));
	size = ft_itoa(lst->content_size);
	ft_mleak(&res, ft_strjoin(res, size));
	free(size);
	return (res);
}
