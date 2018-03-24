#include <stdio.h>
#include <wchar.h>
#include "./inc/ft_printf.h"
#include <locale.h>
#include <stdlib.h>

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
}