#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libftprintf.h"
# include <stdio.h> //DELETE after done!

typedef struct	s_format
{
	int			minus;
	int			plus;
	int			space;
	int			hash;
	int			zero;
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
void			free_format(t_format **format);

/*
 ** handle_flags.c
*/
int				handle_flags(char *fstr, t_format *format);

#endif
