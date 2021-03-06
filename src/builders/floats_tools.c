/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floats_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzabrots <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 15:06:39 by dzabrots          #+#    #+#             */
/*   Updated: 2018/05/18 15:06:41 by dzabrots         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

char			*check_sign(long double *num)
{
	if (*num < 0)
	{
		*num *= -1;
		return ("-");
	}
	else
		return (NULL);
}

static void		prec_hex(int prec, long double *num, char *alph, char **dot)
{
	int			i;

	i = 0;
	while (prec > 0)
	{
		*num -= (intmax_t)(*num);
		*num *= 16.0;
		(*dot)[i] = alph[(intmax_t)(*num)];
		i++;
		prec--;
	}
	(*dot)[i] = '\0';
}

static void		no_prec_hex(long double *num, char *alph, char **dot)
{
	int			i;

	i = 0;
	while (num != 0)
	{
		*num -= (intmax_t)(*num);
		*num *= 16.0;
		if (*num == 0)
			break ;
		(*dot)[i] = alph[(intmax_t)(*num)];
		i++;
	}
	(*dot)[i] = '\0';
}

char			*f_to_hexstr(int prec, long double num)
{
	char		*str;
	char		*dot;
	char		*alph;

	alph = ft_strdup("0123456789abcdef");
	str = ft_itoa_base(num, 16);
	if (prec <= 0 && num == 0)
		return (str);
	if (prec == 0 || num - (intmax_t)num == 0)
		return (str);
	ft_mleak(&str, ft_strjoin(str, "."));
	dot = ft_strnew(prec);
	if (prec > 0)
		prec_hex(prec, &num, alph, &dot);
	else
		no_prec_hex(&num, alph, &dot);
	ft_mleak(&str, ft_strjoin(str, dot));
	free(alph);
	free(dot);
	return (str);
}
