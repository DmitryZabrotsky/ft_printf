#include <stdio.h>
#include "./inc/ft_printf.h"

static char				*check_sign(long double *num)
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
	ft_dmleak
int ft_assign(char **src, char *dst)
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
			ft_assign(&res, ft_strjoin("0", res));
			ft_assign(&res, ft_strjoin("e-", res));
		}
		else
			ft_assign(&res, ft_strjoin("e-", res));
	}
	else
	{
		res = ft_itoa(e);
		if (e < 10)
			ft_assign(&res, ft_strjoin("e+0", res));
		else
			ft_assign(&res, ft_strjoin("e+", res)); 
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
	printf("e: %i  num: %Lf  exp: %s\n%Le\n%La\n", e, num, find_exp(e), f, f);
}

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

