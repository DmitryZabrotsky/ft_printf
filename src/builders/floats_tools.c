#include "../../inc/ft_printf.h"

char		*check_sign(long double *num)
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
	int		i;

	i = 0;
	while (prec > 0)
	{
		*num -= (intmax_t)(*num);
		*num *= 16;
		(*dot)[i] = alph[(intmax_t)(*num)];
		i++;
		prec--;
	}
}

static void		no_prec_hex(long double *num, char *alph, char **dot)
{
	int		i;

	i = 0;
	while (num != 0)
	{
		*num -= (intmax_t)(*num);
		*num *= 16;
		if (*num == 0)
			break ;
		(*dot)[i] = alph[(intmax_t)(*num)];
		i++;
	}
}

char		*f_to_hexstr(int prec, long double num)
{
	char	*str;
	char	*dot;
	int		i;
	char alph[16] = "0123456789abcdef";

	str = ft_itoa_base(num, 16);
	if (prec <= 0)
		return (str);
	ft_mleak(&str, ft_strjoin(str, "."));
	dot = ft_strnew(prec);
	i = 0;
	if (prec > 0)
		prec_hex(prec, &num, alph, &dot);
	else
		no_prec_hex(&num, alph, &dot);
	ft_mleak(&str, ft_strjoin(str, dot));
	free(dot);
	return (str);
}