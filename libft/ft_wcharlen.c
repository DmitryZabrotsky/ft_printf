/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcharlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzabrots <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 12:31:51 by dzabrots          #+#    #+#             */
/*   Updated: 2018/05/03 12:32:03 by dzabrots         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_wcharlen(wchar_t wchr)
{
	size_t res;

	if (!wchr)
		return (0);
	res = 0;
	if (wchr <= 0x7F)
		res = 1;
	else if (wchr <= 0x7FF)
		res = 2;
	else if (wchr <= 0xFFFF)
		res = 3;
	else if (wchr <= 0x10FFFF)
		res = 4;
	return (res);
}
