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
	char		*size;
	char		type;
}				t_format;

/*
 ** init_format.c
*/
t_format		*init_format(void);
void			print_format(t_format *format);
void			free_format(t_format **format);
void 			print_format_table(t_format *format);

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

/*
 ** percision_handler.c
*/
int				handle_precision(const char *fstr, t_format *format, va_list args);

/*
 ** size_handler.c
*/
int				handle_size(const char *fstr, t_format *format);

/*
 ** type_handler.c
 */
int				handle_type(const char *fstr, t_format *format);

/*
  ** string_assembler.c
*/
char			*assemble_string(t_format *format, va_list args);

/*
 ** builders/c_builder.c
*/
char			*build_c(t_format *format, va_list args);

/*
 ** builders/s_builder.c
*/
char			*build_s(t_format *format, va_list args);

/*
 ** tools.c
*/
void			set_precision(char **str, size_t precision);
char			*set_width(int minus, size_t width, char *arg);
void			sp_to_zero(char **str, size_t width);

/*
 ** /builders/build_di.c
*/
char			*build_di(t_format *format, va_list args);

/*
 ** /builders/numtools.c
*/
char			*set_sign(t_format *format, char *arg);

#endif
