/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzabrots <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 16:08:41 by dzabrots          #+#    #+#             */
/*   Updated: 2017/11/24 15:45:37 by dzabrots         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s)
{
	size_t start;
	size_t end;

	if (!s)
		return (NULL);
	start = 0;
	while (ISWHITE(s[start]))
		start++;
	end = ft_strlen(s) - 1;
	while ((ISWHITE(s[end])) && end > 0)
		end--;
	if (start > end)
		return (ft_strdup(""));
	return (ft_strsub(s, start, end - start + 1));
}
