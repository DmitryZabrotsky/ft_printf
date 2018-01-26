/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzabrots <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 21:28:36 by dzabrots          #+#    #+#             */
/*   Updated: 2017/11/24 18:27:20 by dzabrots         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		count_words(const char *str, char c)
{
	int i;
	int counter;

	i = 0;
	counter = 0;
	while (str[i])
	{
		if (str[i] == c)
			i++;
		else
		{
			counter++;
			while (str[i] != c && str[i])
				i++;
		}
	}
	return (counter);
}

static int		ft_strclen(char const *str, char c)
{
	int i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

static char		**clear(char **res)
{
	int i;

	i = 0;
	while (res[i])
	{
		free(res[i]);
		i++;
	}
	free(res);
	return (NULL);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**res;
	int		i;
	int		j;

	i = 0;
	if (!s ||
			!(res = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1))))
		return (NULL);
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			if (!(*res = ft_strnew(sizeof(char) * (ft_strclen(s + i, c) + 1))))
				return (clear(res));
			j = 0;
			while (s[i] != c && s[i])
				(*res)[j++] = s[i++];
			(*res)[j] = '\0';
			res++;
		}
	}
	*res = NULL;
	return (res - count_words(s, c));
}
