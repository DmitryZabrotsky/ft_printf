/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzabrots <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 16:51:36 by dzabrots          #+#    #+#             */
/*   Updated: 2018/05/18 16:51:37 by dzabrots         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

int			handle_string(const char *fstr, t_list **lst, t_flags *flags)
{
	char	*str;
	int		i;

	str = NULL;
	i = 0;
	while (fstr[i] && fstr[i] != '%')
		i++;
	if (i)
	{
		str = ft_strsub(fstr, 0, i);
		ft_lstaddend(lst, ft_lstnew(str, i + 1));
		free(str);
		if (!flags->color)
			flags->color = ft_strdup(" ");
		else
			ft_mleak(&flags->color, ft_strjoin(flags->color, ", "));
	}
	return (i);
}
