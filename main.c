#include "libftprintf.h"
#include <stdio.h>

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

	char chr = 'Y';
	ft_printf("%-10c\n", chr);

	char *str = "Hello ft_printf!";
	ft_printf("%-10s\n", str);

	int p = 532;
	int n = -36;
	ft_printf("%i\n%d\n", p, n);
}
