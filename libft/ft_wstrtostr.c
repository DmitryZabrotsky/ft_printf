/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrtostr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzabrots <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 12:33:59 by dzabrots          #+#    #+#             */
/*   Updated: 2018/05/03 12:34:23 by dzabrots         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_wstrtostr(wchar_t *wstr)
{
	size_t	len;
	wchar_t	i;
	char	*res;
	char	*buf;

	if (!wstr)
		return (NULL);
	len = ft_wstrlen(wstr) + 1;
	res = (char *)malloc(sizeof(char) * len);
	res[len] = '\0';
	i = 0;
	while (wstr[i])
	{
		buf = ft_wchartochar(wstr[i]);
		ft_mleak(&res, ft_strjoin(res, buf));
		free(buf);
		i++;
	}
	return (res);
}
