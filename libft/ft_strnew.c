/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzabrots <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 17:28:33 by dzabrots          #+#    #+#             */
/*   Updated: 2017/11/19 18:36:36 by dzabrots         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnew(size_t size)
{
	char	*str;
	size_t	s_size;

	s_size = size + 1;
	str = (char *)malloc(sizeof(char) * s_size);
	if (!str)
		return (NULL);
	ft_bzero(str, s_size);
	return (str);
}
