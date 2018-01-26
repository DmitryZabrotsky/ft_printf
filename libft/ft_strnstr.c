/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzabrots <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 12:50:06 by dzabrots          #+#    #+#             */
/*   Updated: 2017/11/25 15:45:54 by dzabrots         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int i;
	int needle_len;

	i = 0;
	needle_len = ft_strlen(needle);
	if (needle_len == 0 && haystack)
		return ((char *)haystack);
	while (*haystack && i <= (int)len - needle_len)
	{
		if (ft_strnequ(haystack, needle, needle_len))
			return ((char *)haystack);
		i++;
		haystack++;
	}
	return (NULL);
}
