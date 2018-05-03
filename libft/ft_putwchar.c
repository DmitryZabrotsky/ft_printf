/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzabrots <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 12:29:58 by dzabrots          #+#    #+#             */
/*   Updated: 2018/05/03 12:31:20 by dzabrots         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putwchar(wchar_t wchr)
{
	if (!wchr)
		return ;
	if (wchr <= 0x7F)
		ft_putchar(wchr);
	else if (wchr <= 0x7FF)
	{
		ft_putchar((wchr >> 6) + 0xC0);
		ft_putchar((wchr & 0x3F) + 0x80);
	}
	else if (wchr <= 0xFFFF)
	{
		ft_putchar((wchr >> 12) + 0xE0);
		ft_putchar(((wchr >> 6) & 0x3F) + 0x80);
		ft_putchar((wchr & 0x3F) + 0x80);
	}
	else if (wchr <= 0x10FFFF)
	{
		ft_putchar((wchr >> 18) + 0xF0);
		ft_putchar(((wchr >> 12) & 0x3F) + 0x80);
		ft_putchar(((wchr >> 6) & 0x3F) + 0x80);
		ft_putchar((wchr & 0x3F) + 0x80);
	}
}
