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

	ft_printf("Privet\n%%\nend of str\n%+-0#*.42jX", 67);
	ft_printf("%+0#.5");
	ft_printf("%+ 0#");


}
