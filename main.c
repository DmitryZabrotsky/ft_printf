#include "libftprintf.h"
#include <stdio.h>
#include <locale.h>

int		main(void)
{
	//char *f = "some text: %+#21.7X\n";
	//char *s = "--- ---\nPRIVET!\n--- ---";
	
	/*ft_putnbr(ft_printf("--- ---\nPRIVET!\n--- ---\n"));
	ft_putstr("\n");
	printf("\n%i\n", printf("п"));

	int len;
	ft_putnbr(len = ft_strlen("п"));
	*/

	/*ft_printf("Privet\n%%\nend of str\n%+-0#*.42jX", 67);
	ft_printf("%+0#.5");
	ft_printf("%+ 0#");*/

	//char chr = 'Y';
	//ft_printf("%-10c\n", chr);
	ft_printf("%c\n", (char)NULL);
	printf("%c\n", (char)NULL);

	// char *str = "Hello ft_printf!";
	// char *str1 = "Hello Dina!";
	// ft_printf("%s\n%s\n", str, str1);
	// printf("%s\n%s\n", str, str1);

	/*int p = 532;
	int n = -74;
	ft_printf("% .10i\n%.10d\n", p, n);


	long D = 123456789;
	signed char hh = -128;
	short h = -32767;
	long l = -2147483648;
	long long ll = -9223372036854775807;
	intmax_t intmax = 24784628376487264;
	size_t s = -10;

	ft_printf("%D\n%hhi\n%hi\n%li\n%lli\n%ji\n%zi\n", D, hh, h, l, ll, intmax, s);*/

	/*int n = 689;

	ft_printf("%#o\n%u\n%#.10x\n%#.10X\n", n, n, n, n);
	printf("%#o\n%u\n%#.10x\n%#.10X\n", n, n, n, n);*/

	/*char *ptr = "Hi!";

	printf("addr of ptr: %20p\n", ptr);
	ft_printf("my addr of ptr: %-20p\n", ptr);
	//ft_printf("my addr of ptr: %#lx\n", ptr);*/


	/*int b = 38;

	ft_printf("%b\n", b);*/


	/*double d = -5.64;
	long double ld = 32.41;

	ft_printf("%020f\n%+-20F\n", d, ld);*/


	/*double e = 0.64;
	long double le = 32.41;

	ft_printf("%.10e\n%+-20E\n", e, le);*/

	/*double a = 6.54;
	long double la = 1.234;

	ft_printf("my: %a %La\n", a, la);
	printf("or: %a %La\n", a, la);*/

	/*setlocale(LC_ALL, "");
	ft_printf("my C: %-10C\nlc: %-10lc\n", L'Ы', L'Ы');
	printf("or: %-10lc\n", L'Ы');*/

	/*setlocale(LC_ALL, "");
	ft_printf("my S: %-20.7S\nls: %-20.7ls\n", L"Привет! Меня зовут ДиЗет!", L"Привет! Меня зовут ДиЗет!");
	printf("or: %-20.7ls\n", L"Привет! Меня зовут ДиЗет!");
	*/
	
	//while (1)
	//{}
}
