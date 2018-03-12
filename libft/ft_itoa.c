/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzabrots <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 17:44:37 by dzabrots          #+#    #+#             */
/*   Updated: 2017/11/20 19:28:06 by dzabrots         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			s_len(intmax_t n)
{
	uintmax_t		nbr;
	int				c;

	c = 0;
	if (n == 0)
		c = 1;
	if (n < 0)
	{
		c++;
		nbr = n * (-1);
	}
	else
		nbr = n;
	while (nbr != 0)
	{
		nbr /= 10;
		c++;
	}
	return (c + 1);
}

static char			*setter(int len, uintmax_t n, int sign)
{
	char			*res;

	if (!(res = (char *)malloc(sizeof(char) * len)))
		return (NULL);
	if (sign)
		res[0] = '-';
	res[--len] = '\0';
	while (--len >= 0 + sign)
	{
		res[len] = n % 10 + '0';
		n /= 10;
	}
	return (res);
}

char				*ft_itoa(intmax_t n)
{
	int				sign;
	uintmax_t		nbr;

	sign = 0;
	if (n < 0)
	{
		sign = 1;
		nbr = -n;
	}
	else
		nbr = n;
	return (setter(s_len(n), nbr, sign));
}
