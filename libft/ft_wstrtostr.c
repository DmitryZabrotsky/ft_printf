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
	char *res;
	char *buf;

	res = ft_strdup("");
	while (*wstr)
	{
		buf = res;
		res = ft_strjoin(buf, ft_wchartochar(*wstr));
		free(buf);
		wstr++;
	}
	return (res);
}
