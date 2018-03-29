#include "libft.h"

int ft_mleak(char **src, char *dst)
{
	if (!(*src) || !(dst))
		return (0);
	free (*src);
	*src = dst;
	return (1);
}