/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzabrots <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 16:20:33 by dzabrots          #+#    #+#             */
/*   Updated: 2018/05/02 16:20:44 by dzabrots         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libftprintf.h"
# include <stdarg.h>
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

typedef struct	s_flags
{
	int			cnull;
	int 		p;
	int 		error;
	char		chr;
}				t_flags;

/*
 ** init_format.c
*/
t_format		*init_format(void);
void			free_format(t_format **format);
t_flags			*init_flags(void);
void			free_flags(t_flags **flags);
void			print_format(t_format *format); // DEL AFTER DONE!!!!
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
int				print_lst(t_list *lst, t_flags *flags);

/*
 ** width_handler.c
*/
int				handle_width(const char *fstr, t_format *format, va_list args);

/*
 ** format_handler.c
*/
int				handle_format(const char *fstr, t_list **lst, va_list args, t_flags *flags);
char			*handle_error(t_format *format, t_flags *flags);

/*
 ** percision_handler.c
*/
int				handle_precision(const char *fstr, t_format *format,
				va_list args);

/*
 ** size_handler.c
*/
int				handle_size(const char *fstr, t_format *format);

/*
 ** type_handler.c
*/
int				handle_type(const char *fstr, t_format *format, t_flags *flags);

/*
  ** string_assembler.c
*/
char			*assemble_string(t_format *format, va_list args, t_flags *flags);

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
void			rounder(int prec, long double *num);
void			set_precision(char **str, size_t precision);
char			*set_width(int minus, size_t width, char *arg);

/*
 ** /builders/build_di.c
*/
char			*build_di(t_format *format, va_list args);

/*
 ** /builders/num_tools.c
*/
char			*set_sign(t_format *format, char *arg);
char			*set_num_precision(int precision, char *arg);
char			*set_free_width(size_t width, int zero);
char			*del_sign(char *arg);
char			*build_zero_str(size_t width, char *num, char *sign);

/*
 ** /builders/oux_builder.c
*/
char			*build_oux(t_format *format, va_list args, t_flags *flags);
void			to_upper(char **str);

/*
 ** /builders/p_builder.c
*/
char			*build_p(t_format *format, va_list args, t_flags *flags);

/*
 ** /builders/f_builder.c
*/
char			*build_f(t_format *format, va_list args);
char			*f_to_str(int prec, long double num);

/*
 ** /builders/floats_tools.c
*/
char			*check_sign(long double *num);
char			*f_to_hexstr(int prec, long double num);

/*
 ** /builders/e_builder.c
*/
char			*build_e(t_format *format, va_list args);

/*
 ** /builders/a_builder.c
*/
char			*build_a(t_format *format, va_list args);

/*
 ** /builders/percent_builder.c
*/
char 			*build_percent(t_format *format);
#endif
