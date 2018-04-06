/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzabrots <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 14:58:32 by dzabrots          #+#    #+#             */
/*   Updated: 2018/04/06 15:00:07 by dzabrots         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_len(uintmax_t num, int base)
{
	size_t		res;

	res = 0;
	if (num == 0)
		res = 1;
	while (num != 0)
	{
		num /= base;
		res++;
	}
	return (res + 1);
}

static void		conversion(uintmax_t num, int base, char *res, size_t len)
{
	char		*map;

	map = "0123456789abcdef";
	res[len] = '\0';
	len--;
	while (num >= (unsigned int)base)
	{
		res[len] = map[num % base];
		num /= base;
		len--;
	}
	res[len] = map[num];
}

char			*ft_itoa_base(uintmax_t num, int base)
{
	char		*res;
	size_t		len;

	if (base < 2 || base > 16)
		return (NULL);
	len = count_len(num, base);
	res = (char *)malloc(sizeof(char) * len);
	conversion(num, base, res, len - 1);
	return (res);
}
