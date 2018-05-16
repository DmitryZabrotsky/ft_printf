#include "libft.h"

void	ft_arrfree(char ***arr)
{
	size_t i;

	i = 0;
	if (*arr)
	{
		while ((*arr)[i])
			free((*arr)[i++]);
		free(*arr);
		*arr = NULL;
	}
}