#include "../../inc/ft_printf.h"

char	*handle_error(t_flags *flags)
{
	char *res;

	res = ft_strnew(1);
	res[0] = flags->chr;
	flags->error = 0;
	flags->chr = '\0';
	return (res);
}

int		handle_format(const char *fstr, t_list **lst, va_list args,
	t_flags *flags)
{
	int i;
	char *str;
	t_format *format;
	t_list *content;

	i = 0;
	format = init_format();
	i += handle_flags(fstr + i, format);
	i += handle_width(fstr + i, format, args);
	i += handle_precision(fstr + i, format, args);
	i += handle_size(fstr + i, format);
	i += handle_type(fstr +i, format, flags);
	if (flags->error)
		str = handle_error(flags);
	else
		str = assemble_string(format, args, flags);

//print_format(format);

	content = ft_lstnew(str, ft_strlen(str) + 1);
	if ((format->type == 'c' || format->type == 'C') &&
		(!(content->content_size - 1) ||
		(size_t)format->width > content->content_size -1))
	{
		content->content_size++;
		flags->cnull = 1;
	}
	ft_lstaddend(lst, content);
	free(str);
	free_format(&format);
	return (i);
}	