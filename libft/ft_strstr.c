/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzabrots <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 12:40:32 by dzabrots          #+#    #+#             */
/*   Updated: 2017/11/24 17:38:28 by dzabrots         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int len;

	if (!(len = ft_strlen(needle)))
		return ((char *)haystack);
	while (*haystack)
	{
		if (ft_strnequ(haystack, needle, len))
			return ((char *)haystack);
		haystack++;
	}
	return (NULL);
}
