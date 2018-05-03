//#include <stdio.h>
//#include <wchar.h>
//#include "./inc/ft_printf.h"
#include "libftprintf.h"
#include <locale.h>
//#include <stdlib.h>

//need func as wchar to lschar* 

/*void	ft_putwchar(wchar_t wchr)
{
	if (!wchr)
		return ;
	if (wchr <= 0x7F)
		ft_putchar(wchr);
	else if (wchr <= 0x7FF)
	{
		ft_putchar((wchr >> 6) + 0xC0);
		ft_putchar((wchr & 0x3F) + 0x80);
	}
	else if (wchr <= 0xFFFF)
	{
		ft_putchar((wchr >> 12) + 0xE0);
		ft_putchar(((wchr >> 6) & 0x3F) + 0x80);
		ft_putchar((wchr & 0x3F) + 0x80);
	}
	else if (wchr <= 0x10FFFF)
	{
		ft_putchar((wchr >> 18) + 0xF0);
		ft_putchar(((wchr >> 12) & 0x3F) + 0x80);
		ft_putchar(((wchr >> 6) & 0x3F) + 0x80);
		ft_putchar((wchr & 0x3F) + 0x80);
	}
}

void	ft_putwstr(wchar_t *wstr)
{
	wchar_t i;

	if (!wstr)
		return ;
	i = 0;
	while (wstr[i])
	{
		ft_putwchar(wstr[i]);
		i++;
	}
}

size_t	ft_wcharlen(wchar_t wchr)
{
	size_t res;

	if (!wchr)
		return (0);
	res = 0;
	if (wchr <= 0x7F)
		res = 1;
	else if (wchr <= 0x7FF)
		res = 2;
	else if (wchr <= 0xFFFF)
		res = 3;
	else if (wchr <= 0x10FFFF)
		res = 4;
	return (res);
}

size_t	ft_wstrlen(wchar_t *wstr)
{
	wchar_t i;
	size_t res;

	i = 0;
	res = 0;
	while (wstr[i])
	{
		res += ft_wcharlen(wstr[i]);
		i++;
	}
	return (res);
}

static void write_two(char **res, wchar_t chr)
{
	(*res)[0] = (chr >> 6) + 0xC0;
	(*res)[1] = (chr & 0x3F) + 0x80;
	(*res)[2] = '\0';
}

static void write_three(char **res, wchar_t chr)
{
	(*res)[0] = (chr >> 12) + 0xE0;
	(*res)[1] = ((chr >> 6) & 0x3F) + 0x80;
	(*res)[2] = (chr & 0x3F) + 0x80;
	(*res)[3] = '\0';
}

static void write_four(char **res, wchar_t chr)
{
	(*res)[0] = (chr >> 18) + 0xF0;
	(*res)[1] = ((chr >> 12) & 0x3F) + 0x80;
	(*res)[2] = ((chr >> 6) & 0x3F) + 0x80;
	(*res)[3] = (chr & 0x3F) + 0x80;
	(*res)[4] = '\0';
}

char	*ft_wchartochar(wchar_t chr)
{
	char *res;

	if (!chr)
		return (NULL);
	res = (char *)malloc(sizeof(char) * 5);
	if (chr <= 0x7F)
	{
		res[0] = chr;
		res[1] = '\0';
	}
	else if (chr <= 0x7FF)
	{
		write_two(&res, chr);
	}
	else if (chr <= 0xFFFF)
	{
		write_three(&res, chr);
	}
	else if (chr <= 0x10FFFF)
	{
		write_four(&res, chr);
	}
	return (res);
}*/

//###################################################//
/*char	*ft_wchartochar(wchar_t chr)
{
	char *res;

	res = (char *)malloc(sizeof(char) * 5);
	if (chr <= 0x7F)
	{
		res[0] = chr;
		res[1] = '\0';
	}
	else if (chr <= 0x7FF)
	{
		res[0] = (chr >> 6) + 0xC0;
		res[1] = (chr & 0x3F) + 0x80;
		res[2] = '\0';
	}
	else if (chr <= 0xFFFF)
	{
		res[0] = (chr >> 12) + 0xE0;
		res[1] = ((chr >> 6) & 0x3F) + 0x80;
		res[2] = (chr & 0x3F) + 0x80;
		res[3] = '\0';
	}
	else if (chr <= 0x10FFFF)
	{
		res[0] = (chr >> 18) + 0xF0;
		res[1] = ((chr >> 12) & 0x3F) + 0x80;
		res[2] = ((chr >> 6) & 0x3F) + 0x80;
		res[3] = (chr & 0x3F) + 0x80;
		res[4] = '\0';
	}
	return (res);
}*/

/*char *ft_wstrtostr(wchar_t *wstr)
{
	size_t len;
	wchar_t i;
	char *res;
	char *buf;

	if (!wstr)
		return (NULL);
	len = ft_wstrlen(wstr) + 1;
	res = (char *)malloc(sizeof(char) * len);
	res[len] = '\0';
	i = 0;
	while (wstr[i])
	{
		buf = ft_wchartochar(wstr[i]);
		free(res);
		ft_mleak(&res, ft_strjoin(res, buf));
		free(buf);
		i++;
	}
	return (res);
}*/

int main(void)
{
	setlocale(LC_ALL, "");
	//(♕ == 9813 == 0x2655)
	wchar_t wc = (wchar_t)0x2655; 
	wchar_t ws[3];
	ws[0] = (wchar_t)0x2655;
	ws[1] = (wchar_t)0x2655;
	ws[2] = (wchar_t)0x0000;

	printf("\n  %i\n", printf("%lc", wc));
	printf("\n  %i\n", printf("%ls", ws));

	printf("MB_CUR_MAX: %i\n", MB_CUR_MAX);

	ft_putwchar(wc);
	ft_putchar('\n');
	ft_putchar('\n');

	char *str;
	str = ft_wchartochar(wc);
	ft_putstr(str);
	ft_putchar('\n');
	ft_putnbr(ft_strlen(str));
	ft_putchar('\n');

	wint_t wi = 0x2655;
	printf("\n  %i\n", printf("%lc", wi));

	ft_putchar('\n');
	ft_putstr("wint_t: ");
	ft_putwchar((wchar_t)wi);
	ft_putchar('\n');
	ft_putchar('\n');

	printf("wint: %lu  wchar: %lu\n", sizeof(wint_t), sizeof(wchar_t));

	ft_putstr("\n");
	ft_putwstr(ws);
	ft_putchar('\n');



	printf("wcharlen: %zu\nwstrlen: %zu\n", ft_wcharlen(wc), ft_wstrlen(ws));
	char *testwtos = ft_wstrtostr(ws);
	printf("wstrtostr: %s     len: %zu\n", testwtos, ft_strlen(testwtos));
}