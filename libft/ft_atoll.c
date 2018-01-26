/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzabrots <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 11:29:05 by dzabrots          #+#    #+#             */
/*   Updated: 2017/11/24 17:43:23 by dzabrots         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long int				ft_atoll(const char *str)
{
	unsigned long long int	res;
	int						flag;

	flag = 0;
	res = 0;
	while (ISWHITE(*str) || *str == '\r' || *str == '\v' || *str == '\f')
		str++;
	if (*str == '-')
	{
		flag = 1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10ULL;
		res += (unsigned long long)(*str - '0');
		if (res > MAX_LL)
			return (flag ? 0 : -1);
		str++;
	}
	return (flag ? (long long int)-res : (long long int)res);
}
