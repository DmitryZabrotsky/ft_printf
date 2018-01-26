/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzabrots <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 18:26:38 by dzabrots          #+#    #+#             */
/*   Updated: 2017/11/24 15:08:03 by dzabrots         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memmove(void *dst, const void *src, size_t n)
{
	char		*d;
	const char	*s;
	size_t		i;

	if (src == dst && n == 0)
		return (dst);
	i = -1;
	d = (char *)dst;
	s = (const char *)src;
	if (s < d)
	{
		while ((int)--n >= 0)
			d[n] = s[n];
	}
	else
	{
		while (++i < n)
			d[i] = s[i];
	}
	return (dst);
}
