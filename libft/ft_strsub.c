/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzabrots <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 14:29:53 by dzabrots          #+#    #+#             */
/*   Updated: 2017/11/20 17:24:16 by dzabrots         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	if (!s)
		return (NULL);
	if ((sub = (char *)malloc(sizeof(char) * (len + 1))))
	{
		i = 0;
		while (s[start + i] && i < len)
		{
			*sub = s[start + i];
			sub++;
			i++;
		}
		*sub = '\0';
		return (sub - len);
	}
	return (NULL);
}
