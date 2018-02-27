#include "ft_printf.h"

int			handle_string(const char *fstr, t_list **lst)
{
	char *str;
	int i;

	str = NULL;
	i = 0;
	while (fstr[i] && fstr[i] != '%')
		i++;
	if (i)
	{
		str = ft_strsub(fstr, 0, i);
		ft_lstaddend(lst, ft_lstnew(str, i + 1));
		free(str);
	}
	return (i);
}