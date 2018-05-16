#include "../../inc/ft_printf.h"

/* ************************************************************************** */


int			handle_color(const char *fstr, t_flags *flags)
{
	int len;

	len = 0;
	if (ft_strnequ(fstr, "BLACK", 5))
	{
		if (!flags->color)
			flags->color = ft_strdup("BLACK");
		else
			ft_mleak(&flags->color, ft_strjoin(flags->color, ",BLACK"));
		len = 5;
	}
	else if (ft_strnequ(fstr, "RED", 3))
	{
		if (!flags->color)
			flags->color = ft_strdup("RED");
		else
			ft_mleak(&flags->color, ft_strjoin(flags->color, ",RED"));
		len = 3;
	}
	else if (ft_strnequ(fstr, "GREEN", 5))
	{
		if (!flags->color)
			flags->color = ft_strdup("GREEN");
		else
			ft_mleak(&flags->color, ft_strjoin(flags->color, ",GREEN"));
		len = 5;
	}
	else if (ft_strnequ(fstr, "YELLOW", 6))
	{
		if (!flags->color)
			flags->color = ft_strdup("YELLOW");
		else
			ft_mleak(&flags->color, ft_strjoin(flags->color, ",YELLOW"));
		len = 6;
	}
	else if (ft_strnequ(fstr, "BLUE", 4))
	{
		if (!flags->color)
			flags->color = ft_strdup("BLUE");
		else
			ft_mleak(&flags->color, ft_strjoin(flags->color, ",BLUE"));
		len = 4;
	}
	else if (ft_strnequ(fstr, "MAGENTA", 7))
	{	
		if (!flags->color)
			flags->color = ft_strdup("MAGENTA");
		else
			ft_mleak(&flags->color, ft_strjoin(flags->color, ",MAGENTA"));
		len = 7;
	}
	else if (ft_strnequ(fstr, "CYAN", 4))
	{
		if (!flags->color)
			flags->color = ft_strdup("CYAN");
		else
			ft_mleak(&flags->color, ft_strjoin(flags->color, ",CYAN"));
		len = 4;
	}
	else if (ft_strnequ(fstr, "WHITE", 5))
	{
		if (!flags->color)
			flags->color = ft_strdup("WHITE");
		else
			ft_mleak(&flags->color, ft_strjoin(flags->color, ",WHITE"));
		len = 5;
	}
	else
		if (!flags->color)
			flags->color = ft_strdup(" ");
		else
			ft_mleak(&flags->color, ft_strjoin(flags->color, ", "));
	return (len);
}