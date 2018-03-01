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
 ** flags_handler.c
*/
int				handle_flags(const char *fstr, t_format *format);

/*
 ** strings_handler.c
*/
int				handle_string(const char *fstr, t_list **lst);

/*
 ** lst_printer.c
*/
int				print_lst(t_list *lst);

/*
 ** width_handler.c
 */
int				handle_width(const char *fstr, t_format *format, va_list args);

/*
 ** format_handler.c
*/
int				handle_format(const char *fstr, t_list **lst, va_list args);

#endif