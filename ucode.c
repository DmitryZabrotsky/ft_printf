#include <stdio.h>
#include <wchar.h>
#include "./inc/ft_printf.h"
#include <locale.h>
#include <stdlib.h>

//need func as wchar to char* 

void	ft_putwchar(wchar_t chr)
{
	if (chr <= 0x7F)
		ft_putchar(chr);
	else if (chr <= 0x7FF)
	{
		ft_putchar((chr >> 6) + 0xC0);
		ft_putchar((chr & 0x3F) + 0x80);
	}
	else if (chr <= 0xFFFF)
	{
		ft_putchar((chr >> 12) + 0xE0);
		ft_putchar(((chr >> 6) & 0x3F) + 0x80);
		ft_putchar((chr & 0x3F) + 0x80);
	}
	else if (chr <= 0x10FFFF)
	{
		ft_putchar((chr >> 18) + 0xF0);
		ft_putchar(((chr >> 12) & 0x3F) + 0x80);
		ft_putchar(((chr >> 6) & 0x3F) + 0x80);
		ft_putchar((chr & 0x3F) + 0x80);
	}
}

int main(void)
{
	setlocale(LC_ALL, "");
	//(♕ == 9813 == 0x2655 == 11100010 10011001 10010101 00001010)
	wchar_t wc = (wchar_t)0x2655; 
	wchar_t ws[3];
	ws[0] = (wchar_t)0x2655;
	ws[1] = (wchar_t)0x2655;
	ws[2] = (wchar_t)0x0000;

	printf("\n  %i\n", printf("%lc", wc));
	printf("\n  %i\n", printf("%ls", ws));

	printf("%i\n", MB_CUR_MAX);

	ft_putwchar(wc);
}