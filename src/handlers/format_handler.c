/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzabrots <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 16:32:16 by dzabrots          #+#    #+#             */
/*   Updated: 2018/05/18 16:34:23 by dzabrots         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

char			*handle_error(t_format *format, t_flags *flags)
{
	char		*str;
	char		*res;

	if (format->width)
	{
		str = ft_strnew(format->width);
		str = (char *)(ft_memset(str, ' ', format->width));
		if (format->minus)
			str[0] = flags->chr;
		else
			str[format->width - 1] = flags->chr;
	}
	else
	{
		str = ft_strnew(1);
		str[0] = flags->chr;
	}
	flags->error = 0;
	flags->chr = '\0';
	res = ft_strdup(str);
	free(str);
	return (res);
}

int static		turn_on_handlers(const char *fstr, t_format *format,
	va_list args, t_flags *flags)
{
	int			i;

	i = 0;
	i += handle_flags(fstr + i, format);
	i += handle_width(fstr + i, format, args);
	i += handle_precision(fstr + i, format, args);
	i += handle_size(fstr + i, format);
	i += handle_type(fstr + i, format, flags);
	i += handle_color(fstr + i, flags);
	return (i);
}

int				handle_format(const char *fstr, t_list **lst, va_list args,
	t_flags *flags)
{
	int			i;
	char		*str;
	t_format	*format;
	t_list		*content;

	i = 0;
	format = init_format();
	i = turn_on_handlers(fstr, format, args, flags);
	if (flags->error)
		str = handle_error(format, flags);
	else
		str = assemble_string(format, args, flags, *lst);
	if (flags->minuscnull)
		content = ft_lstnew(str, format->width);
	else
		content = ft_lstnew(str, ft_strlen(str) + 1);
	if ((format->type == 'c' || format->type == 'C') &&
		(!(content->content_size - 1) ||
		(size_t)format->width > content->content_size - 1))
	{
		content->content_size++;
		flags->cnull = 1;
	}
	ft_lstaddend(lst, content);
	free(str);
	free_format(&format);
	return (i);
}
