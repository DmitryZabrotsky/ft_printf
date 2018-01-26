/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzabrots <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 14:11:05 by dzabrots          #+#    #+#             */
/*   Updated: 2017/11/24 14:40:10 by dzabrots         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char *d;
	unsigned char *s;

	if (dest == src)
		return (dest);
	d = (unsigned char*)dest;
	s = (unsigned char*)src;
	while (n--)
	{
		*d++ = *s++;
	}
	return (dest);
}
