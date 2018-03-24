#include <stdio.h>
#include "./inc/ft_printf.h"

char *f_to_str(int prec, long double num)
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
}

int main(void)
{
	//double f = 12;
	//printf("%f\n%20e\n%20a\n\n", f, f, f);
	//PRIVET GIT!
	long double num = 64;
	printf("%Lf\n", num);
	printf("%.64Lf\n\n", num);
	num += 1e-9;
	printf("%.64Lf\n\n\n", num);
	printf("\n%s\n", f_to_str(6 ,num));
}

