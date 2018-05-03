/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wchartochar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzabrots <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 12:33:07 by dzabrots          #+#    #+#             */
/*   Updated: 2018/05/03 12:33:50 by dzabrots         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		write_two(char **res, wchar_t chr)
{
	(*res)[0] = (chr >> 6) + 0xC0;
	(*res)[1] = (chr & 0x3F) + 0x80;
	(*res)[2] = '\0';
}

static void		write_three(char **res, wchar_t chr)
{
	(*res)[0] = (chr >> 12) + 0xE0;
	(*res)[1] = ((chr >> 6) & 0x3F) + 0x80;
	(*res)[2] = (chr & 0x3F) + 0x80;
	(*res)[3] = '\0';
}

static void		write_four(char **res, wchar_t chr)
{
	(*res)[0] = (chr >> 18) + 0xF0;
	(*res)[1] = ((chr >> 12) & 0x3F) + 0x80;
	(*res)[2] = ((chr >> 6) & 0x3F) + 0x80;
	(*res)[3] = (chr & 0x3F) + 0x80;
	(*res)[4] = '\0';
}

char			*ft_wchartochar(wchar_t chr)
{
	char		*res;

	if (!chr)
		return (NULL);
	res = (char *)malloc(sizeof(char) * 5);
	if (chr <= 0x7F)
	{
		res[0] = chr;
		res[1] = '\0';
	}
	else if (chr <= 0x7FF)
	{
		write_two(&res, chr);
	}
	else if (chr <= 0xFFFF)
	{
		write_three(&res, chr);
	}
	else if (chr <= 0x10FFFF)
	{
		write_four(&res, chr);
	}
	return (res);
}
