#include "libftprintf.h"
#include <stdio.h>
#include <locale.h>

int main(void)
{
	ft_printf("my: {%S}", NULL);
	printf("or: {%S}", NULL);
}

// int main(void)
// {
// 	ft_printf("my: %%\n");
// 	printf("or: %%\n");

// 	ft_printf("my: aa%%bb\n");
// 	printf("or: aa%%bb\n");

// 	ft_printf("my: %%%%%%%%%%\n");
// 	printf("or: %%%%%%%%%%\n");

// 	ft_printf("my: .%%.%%.%%.%%.%%.%%.%%.%%.\n");
// 	printf("or: .%%.%%.%%.%%.%%.%%.%%.%%.\n");
	
// 	ft_printf("my: %"); // inv conv
// 	printf("or: %");

// 	ft_printf("my: % Zoooo\n"); // inv conv
// 	printf("or: % Zoooo\n");

// 	ft_printf("my: {%}\n"); //inv conv
// 	printf("or: {%}\n");

// 	ft_printf("my: {% %}\n");
// 	printf("or: {% %}\n");
// }

// int		main(void)
// {
//   //ft_printf("%.2c", NULL);
//   //ft_printf("@moulitest: %c", 0);
//   //ft_printf("%2c", 0);
//   //ft_printf("null %c and text", 0);
//   //ft_printf("% c", 0);
//   //ft_printf("%p\n", 0);
// 	// ft_printf("%hU\n", 4294967296);
//  	//  ft_printf("%U\n", 4294967296);

// 	// ft_printf("my: %#.o %#.0o\n", 0, 0); //nothing out
// 	// printf("@or: %#.o %#.0o\n", 0, 0);

// 	// ft_printf("my: %.o %.0o\n", 0, 0); //0 out
// 	// printf("or: %.o %.0o\n", 0, 0);
// 	// ft_printf("my: %5.o %5.0o\n", 0, 0);
// 	// printf("or: %5.o %5.0o\n", 0, 0);


// 	// ft_printf("%#6o\n", 2500);
// 	// printf("%#6o\n", 2500);
// 	// ft_printf("%-#6o\n", 2500);
// 	// printf("%-#6o\n", 2500);


// 	//char *f = "some text: %+#21.7X\n";
// 	//char *s = "--- ---\nPRIVET!\n--- ---";
	
// 	/*ft_putnbr(ft_printf("--- ---\nPRIVET!\n--- ---\n"));
// 	ft_putstr("\n");
// 	printf("\n%i\n", printf("п"));

// 	int len;
// 	ft_putnbr(len = ft_strlen("п"));
// 	*/

// 	/*ft_printf("Privet\n%%\nend of str\n%+-0#*.42jX", 67);
// 	ft_printf("%+0#.5");
// 	ft_printf("%+ 0#");*/

// 	//char chr = 'Y';
// 	//ft_printf("%-10c\n", chr);
// 	//ft_printf("%d\n", ft_printf("%c", (char)NULL));
// 	//printf("%d\n", printf("%c", (char)NULL));

// 	// char *str = "Hello ft_printf!";
// 	// char *str1 = "Hello ACDZ!";
// 	// ft_printf("%s\n%s\n", str, str1);
// 	// printf("%s\n%s\n", str, str1);

// 	// ft_printf("%s\n", NULL);
// 	// printf("%s\n", NULL);

// 	/*int p = 532;
// 	int n = -74;
// 	ft_printf("% .10i\n%.10d\n", p, n);


// 	long D = 123456789;
// 	signed char hh = -128;
// 	short h = -32767;
// 	long l = -2147483648;
// 	long long ll = -9223372036854775807;
// 	intmax_t intmax = 24784628376487264;
// 	size_t s = -10;

// 	ft_printf("%D\n%hhi\n%hi\n%li\n%lli\n%ji\n%zi\n", D, hh, h, l, ll, intmax, s);*/

// 	/*int n = 689;

// 	ft_printf("%#o\n%u\n%#.10x\n%#.10X\n", n, n, n, n);
// 	printf("%#o\n%u\n%#.10x\n%#.10X\n", n, n, n, n);*/

// 	/*char *ptr = "Hi!";

// 	printf("addr of ptr: %20p\n", ptr);
// 	ft_printf("my addr of ptr: %-20p\n", ptr);
// 	//ft_printf("my addr of ptr: %#lx\n", ptr);*/


// 	/*int b = 38;

// 	ft_printf("%b\n", b);*/


// 	// double d = -5.64;
// 	// long double ld = 32.41;
// 	// double d = 1;
// 	// long double ld = 1;

// 	// ft_printf("%020f\n%+-20F\n", d, ld);
// 	// printf("%020f\n%+-20LF\n", d, ld);


// 	// double e = 0.96;
// 	// long double le = 0.96;

// 	// test case: 42.000000
// 	// test case: 1001.000000
// 	// test case: -8000.000000
// 	// test case: 0.000000
// 	// test case: 0.000000
// 	// test case: 2147483647.000000
// 	// test case: -2147483648.000000
// 	// test case: -2147483649.000000
// 	// test case: 2147483648.000000
// 	// test case: 34.000000
// 	// test case: 9.000000
// 	// test case: 503.000000
// 	// test case: 42.420000
// 	// test case: 42.000000
// 	// test case: 1001.000000
// 	// test case: -8000.000000
// 	// test case: 0.000000
// 	// test case: 0.000000
// 	// test case: 2147483647.000000
// 	// test case: -2147483648.000000
// 	// test case: -2147483649.000000
// 	// test case: 2147483648.000000
// 	// test case: 34.000000
// 	// test case: 9.000000
// 	// test case: 503.000000
// 	// test case: 42.420000
// 	// test case: 42.420000

// 	// double e = -2147483648.000000;
// 	// long double le = -2147483648.000000;

// 	// ft_printf("\nmy 'e': %.15e my 'LE': %.15LE\n", e, le);
// 	// printf("or 'e': %.15e or 'LE': %.15LE\n\n", e, le);

// 	// double a = 42.42;
// 	// long double la = 42.42;
// 	// double a = -2147483648.000000;
// 	// long double la = -2147483648.000000;
// 	// ft_printf("\nmy: %a %La\n", a, la);
// 	// printf("or: %a %La\n\n", a, la);

// 	//setlocale(LC_ALL, "");
// 	// ft_printf("%lc\n", L'ø');
// 	// ft_putnbr((char)L'ø');
// 	// printf("%lc\n", L'ø');
// 	// ft_printf("return: %d\n", ft_printf("my C: %-10C\nlc: %-10lc\n", L'Ы', L'Ы'));
// 	//ft_printf("return: %d\n", ft_printf("lc: %-10lc\n", L'Ы'));
// 	//printf("return: %d\n", printf("or: %-10lc\n", L'Ы'));
// 	// printf("return: %d\n", printf("or: %10lc%10lc%10lc\nls", L'W', L'У', L'B'));
// 	// ft_printf("return: %d\n", ft_printf("my: %10lc%10lc\n",  L'W', L'У'));

// 	//printf("or: %10lc%10lc%10lc\nls", L'W', L'У', L'B');

// 	/*setlocale(LC_ALL, "");
// 	ft_printf("my S: %-20.7S\nls: %-20.7ls\n", L"Привет! Меня зовут ДиЗет!", L"Привет! Меня зовут ДиЗет!");
// 	printf("or: %-20.7ls\n", L"Привет! Меня зовут ДиЗет!");
// 	*/
	
// 	//while (1)
// 	//{}

// 	// ft_printf("@moulitest: %#.x %#.0x", 0, 0);
// 	// printf("@moulitest: %#.x %#.0x", 0, 0);

// 	// ft_printf("@moulitest: %.d %.0d", 0, 0);
// 	// printf("@moulitest: %.d %.0d", 0, 0);
// }
