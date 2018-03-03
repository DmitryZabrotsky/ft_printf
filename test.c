#include <stdio.h>
#include "./libft/libft.h"
#include <wchar.h>

int main(void)
{
	/*int i = 0;
	int x = 8;

	++i = i + x;
	printf("%i\n", i);
	*/
//	wchar_t c = L'ы';
//	printf("---> %C", c);
	//ft_putstr("p");

	char *str = "stroka";
	int i = 63;
	int si = -3666;

	printf("%20.3s\n%-#20.5x\n%- 20d\n", str, i, si);
}
