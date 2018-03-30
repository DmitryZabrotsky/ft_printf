#include <stdio.h>
#include "./inc/ft_printf.h"

int f_to_a(long double *num)
{
	int p;

	p = 0;
	while (8 > (intmax_t)(*num) || 16 < (intmax_t)(*num))
	{
		//printf("in while: %Lf\n", *num);
		if ((intmax_t)(*num) < 8)
		{
			*num *= 2;
			p--;
		}
		if ((intmax_t)(*num) > 16)
		{
			*num /= 2;
			p++;
		}
	}
	return (p);
}

static char				*find_exp(int p)
{
	char				*res;

	if (p < 0)
	{
		p *= -1;
		res = ft_itoa(p);
		if (p < 10)
			ft_mleak(&res, ft_strjoin("p-", res));
		else
			ft_mleak(&res, ft_strjoin("p-", res));
	}
	else
	{
		res = ft_itoa(p);
		ft_mleak(&res, ft_strjoin("p+", res)); 
	}
	return (res);
}

char				*f_to_hexstr(int prec, long double num)
{
	char *str;
	char *dot;
	int i;
	char alph[16] = "0123456789abcdef";

	str = ft_itoa_base(num, 16);
	if (prec > 0)
	{
		str = ft_strjoin(str, ".");
		dot = ft_strnew(prec);
		i = 0;
		while (prec > 0)
		{
			num -= (intmax_t)num;
			num *= 16;
			dot[i] = alph[(intmax_t)num];
			i++;
			prec--;
		}
		str = ft_strjoin(str, dot);
	}
	return (str);
}

int main(void)
{
	long double f = 2;
	printf("PRF: %La\n", f);
	long double num = f;
	char *res;
	char *exp;

	check_sign(&num);
	exp = find_exp(f_to_a(&num));
	res = f_to_hexstr(15, num);
	res = ft_strjoin("0x", res);
	res = ft_strjoin(res, exp);
	printf("p: %.15La\nres: %s\n", f, res);
}

/*static char				*check_sign(long double *num)
{
	if (*num < 0)
	{
		*num *= -1;
		return ("-"); 
	}
	else
		return (NULL);
}

int f_to_e(long double *num)
{
	int e;

	e = 0;
	while (1 > (int)(*num) || 9 < (int)(*num))
	{
		printf("while!\n");
		if ((int)(*num) < 1)
		{
			*num *= 10;
			e--;
			printf("e--: %i\n", e);
		}
		if ((int)(*num) > 9)
		{
			*num /= 10;
			e++;
			printf("e++: %i\n", e);
		}
	}
	return (e);
}
	
int ft_mleak(char **src, char *dst)
{
	if (!(*src) || !(dst))
		return (0);
	free (*src);
	*src = dst;
	return (1);
}

char *find_exp(int e)
{
	char *res;

	if (e < 0)
	{
		e *= -1;
		res = ft_itoa(e);
		if (e < 10)
		{	
			ft_mleak(&res, ft_strjoin("0", res));
			ft_mleak(&res, ft_strjoin("e-", res));
		}
		else
			ft_mleak(&res, ft_strjoin("e-", res));
	}
	else
	{
		res = ft_itoa(e);
		if (e < 10)
			ft_mleak(&res, ft_strjoin("e+0", res));
		else
			ft_mleak(&res, ft_strjoin("e+", res)); 
	}
	return (res);
}
//01234567890123456789012345678901234567890123456789012345678901234567890123456789
int main(void)
{
	long double f = -1.02;
	long double num = f;
	int e;

	check_sign(&num);
	e = f_to_e(&num);
	printf("e: %i  num: %Lf  exp: %s\n%.0Le\n%La\n", e, num, find_exp(e), f, f);
}*/

/*char *f_to_str(int prec, long double num)
{
	char *str;
	char *dot;
	int i;
	//int len;

	str = ft_itoa(num);
	if (prec > 0)
	{	
		str = ft_strjoin(str, ".");
		dot = ft_strnew(prec);
		i = 0;
		while (prec > 0)
		{
			num -= (int)num;
			printf("num -= %Lf\n", num);
			num *= 10;
			printf("num *= %Lf\n", num);
			//str = ft_strjoin(str, ft_itoa(num));
			dot[i] = '0' + (int)num;
			printf("dot[%i] %s\n", i, dot);
			i++;
			prec--;
			//printf("str[%i] = %s\n", prec, str);
		}
		str = ft_strjoin(str, dot);
	}
	return (str);
}*/

/*int main(void)
{
	double f = 45.64;
	printf("%f\n%.64e\n%.64a\n\n", f, f, f);
	
	//PRIVET GIT!
	long double num = 64.654;
	printf("\n%+020Lf\n\n", num);
	printf("%.64Lf\n\n", num);
	num += 1e-9;
	printf("%.64Lf\n\n\n", num);
	printf("\n%s\n", f_to_str(2 ,num));

	double d = 5.64;
	printf("%f\n\n", d);
	printf("%s\n", f_to_str(6, (long double)d));
}*/

