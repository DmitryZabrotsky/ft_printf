#include <stdio.h>
#include "./libft/libft.h"
#include <wchar.h>

/*void		set_precision(char **str, size_t precision)
{
	size_t	len;
	size_t	del;

	len = ft_strlen(*str);
	printf("strlen: %zu\n", len);
	if (len > precision)
	{
		del = len - precision;
		printf("del: %zu\n", del);
		ft_memset(*str + precision, '\0', del);
		printf("%s\n", *str);
	}
}
*/

void to_upper(char **str)
{
	int i;

	i = 0;
	while ((*str)[i])
	{
		if ((*str)[i] >= 'a' && (*str)[i] <= 'z')
			(*str)[i] = (*str)[i] - 32;
		printf("%c\n", (*str)[i]);
		i++;
	}
}

int main(void)
{
//	int i = 543;
//	int d = -219;
	char *str = ft_strdup("0x142hello!");
	to_upper(&str);
	printf("%s\n", str);
//	printf("%s\n%s\n%x\n", ft_itoa(i), ft_itoa(d), d);

//	printf("%- .10i\n%.10d\n", i, d);
	
//	printf("%hhi %hi %li %lli %ji %zi", d, d, d, d, d, d);

	/*char *h;
	h = ft_strdup("hello");
	set_precision(&h, 3);
	ft_putendl(h);*/
	
	/*int i = 0;
	int x = 8;

	++i = i + x;
	printf("%i\n", i);
	*/
//	wchar_t c = L'ы';
//	printf("---> %C", c);
	//ft_putstr("p");

	/*char c = 'C';
	char *str = "stroka";
	int i = 63;
	int si = -3666;

	printf("%10c\n%20.15s\n%-#20.5x\n%20.10d\n", c, str, i, si);
*/
}
