/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzabrots <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 12:32:13 by dzabrots          #+#    #+#             */
/*   Updated: 2018/05/03 12:32:44 by dzabrots         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_wstrlen(wchar_t *wstr)
{
	size_t	res;

	res = 0;
	while (*wstr)
	{
		res += ft_wcharlen(*wstr);
		wstr++;
	}
	return (res);
}
