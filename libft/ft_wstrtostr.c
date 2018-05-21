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
	char *buf1;

	res = ft_strdup("");
	while (*wstr)
	{
		buf = res;
		buf1 = ft_wchartochar(*wstr);
		res = ft_strjoin(buf, buf1);
		free(buf);
		free(buf1);
		wstr++;
	}
	return (res);
}
