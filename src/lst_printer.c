/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_printer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzabrots <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 15:15:53 by dzabrots          #+#    #+#             */
/*   Updated: 2018/04/06 15:16:05 by dzabrots         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void		put_content(t_list *lst)
{
	char	*str;
	size_t	i;

	i = 0;
	str = (char *)lst->content;
	while (i != lst->content_size - 1)
	{
		ft_putchar(str[i]);
		i++;
	}
}

void		print_color(char **colors, int i)
{
	if (ft_strequ(colors[i], "BLACK"))
		ft_putstr(BLACK);
	else if (ft_strequ(colors[i], "RED"))
		ft_putstr(RED);
	else if (ft_strequ(colors[i], "GREEN"))
		ft_putstr(GREEN);
	else if (ft_strequ(colors[i], "YELLOW"))
		ft_putstr(YELLOW);
	else if (ft_strequ(colors[i], "BLUE"))
		ft_putstr(BLUE);
	else if (ft_strequ(colors[i], "MAGENTA"))
		ft_putstr(MAGENTA);
	else if (ft_strequ(colors[i], "CYAN"))
		ft_putstr(CYAN);
	else if (ft_strequ(colors[i], "WHITE"))
		ft_putstr(WHITE);
}

void static		check_color(t_list *lst, t_flags *flags, char **colors, int i)
{
	if (flags->color && colors && !ft_strequ(colors[i], " "))
	{
		print_color(colors, i);
		put_content(lst);
		ft_putstr(RESET);
	}
	else
		put_content(lst);
}

void static		printer(t_list *lst, t_flags *flags, char **colors, int *chars)
{
	int i;

	i = 0;
	while (lst)
	{
		if (!flags->n)
			check_color(lst, flags, colors, i);
		if (flags->minuscnull)
		{
			*chars += flags->len;
			flags->minuscnull = 0;
			flags->len = 0;
		}
		else
		{
			*chars += ft_strlen((char *)lst->content);
			*chars += flags->cnull;
			flags->cnull = 0;
		}
		lst = lst->next;
		i++;
	}
}

int			print_lst(t_list *lst, t_flags *flags)
{
	int		chars;
	char	**colors;

	if (!lst)
		return (0);
	colors = ft_strsplit(flags->color, ',');
	chars = 0;
	printer(lst, flags, colors, &chars);
	if (!flags->n)
		free(flags->color);
	ft_arrfree(&colors);
	return (chars);
}
