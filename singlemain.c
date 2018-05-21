#include "libftprintf.h"
#include <stdio.h>
#include <locale.h>

int main(void)
{
// - c
	setlocale(LC_ALL, "");
		ft_printf("%-10c\n	", 'Y');
// - C 
		ft_printf("%-10lc\n", L'ø');
// - s
		ft_printf("%-20.2s\n", "AC <3 DZ\n");
// - S
		ft_printf("%-40.4S\n", L"ݗݜशব");
// - d
		ft_printf("%0+20.10d\n", 2048);
// - D
		ft_printf("%D\n", 2147483647);
// - i
		ft_printf("%0+20.10i\n", 2048);
// - o
		ft_printf("%#020.10o\n", 4242);
// - O	
		ft_printf("%#020.10O\n", 4242);
// - u
		ft_printf("%#020.10U\n", 4294967295);
// - U
  		ft_printf("%#020.10u\n", 4294967295);
// - x
		ft_printf("%#20.10x\n", 2048);
// - X
		ft_printf("%#20.10X\n", 4096);
// - %
		ft_printf("%-10%\n");
// - f
		ft_printf("%020.10f\n", -42.42);
// - F
		long double ld = -42.42;
		ft_printf("%20.10Lf\n", ld);
// - a 
		ft_printf("%020.10a\n", 42.42);
// - A 
		ft_printf("%020.10A\n", 42.42);
// - e
		ft_printf("%020.10e\n", 42.42);
// - E
		ft_printf("%020.10E\n", 42.42);
// - b
		ft_printf("%b\n", 64);
// - p
		ft_printf("%p\n", &ft_printf);
// - t
		char *str = ft_strdup("AC <3 DZ!");
		t_list	*lst = ft_lstnew(str, ft_strlen(str));
		ft_printf("%t\n", lst);
		free(str);
		ft_lstfree(&lst);
// - n
		int box;
		ft_printf("eyou say hello!%n\n", &box);
		ft_printf("%i\n", box);
// colors
		ft_printf("%sMAGENTA %sRED %sBLUE\n", " AC", " <3", " DZ");
// fails from moulitest	
	ft_printf("{%04d}\n", 10000);

  ft_printf("\n");
  ft_printf("%%\n");
  ft_printf("%d\n", 42);
  ft_printf("%d%d\n", 42, 41);
  ft_printf("%d%d%d\n", 42, 43, 44);
  ft_printf("%ld\n", 2147483647);
  ft_printf("%lld\n", 9223372036854775807);
  ft_printf("%x\n", 505);
  ft_printf("%X\n", 505);
  ft_printf("%p\n", &ft_printf);
  ft_printf("%20.15d\n", 54321);
  ft_printf("%-10d\n", 3);
  ft_printf("% d\n", 3);
  ft_printf("%+d\n", 3);

	ft_printf("%010d\n", 1);
  
  ft_printf("%hhd\n", 0);
  ft_printf("%jd\n", 9223372036854775807);
  ft_printf("%zd\n", 4294967295);
 
	ft_printf("%\n");

  ft_printf("%U\n", 4294967295);
  ft_printf("%u\n", 4294967295);
  ft_printf("%o\n", 40);
  ft_printf("%%#08x\n", 42);
  ft_printf("%x\n", 1000);
  ft_printf("%#X\n", 1000);
  ft_printf("%s\n", NULL);
  ft_printf("%S\n", L"ݗݜशব");
  ft_printf("%s%s\n", "test", "test");
  ft_printf("%s%s%s\n", "test", "test", "test");
  ft_printf("%C\n", 15000);


	ft_printf("{%10R}");
	ft_printf("{%-15Z}", 123);
	
	while (1)
	{}
}