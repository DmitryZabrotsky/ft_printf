#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libftprintf.h"
# include <stdio.h> //DELETE after done!

typedef	struct	s_flags
{
	int			minus;
	int			plus;
	int			space;
	int			hash;
	int			zero;
}				t_flags;

typedef struct	s_format
{
	t_flags		*flags;
	int			width;
	int			precision;
	char		*type;
	char		conversion;
}				t_format;

/*
 ** init_format.c
*/
t_format		*init_format(void);
void			print_format(t_format *format);

#endif
