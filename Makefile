all:
	gcc -Wall -Wextra -Werror main.c ft_printf.c ft_printf.h flags_handler.c lst_printer.c format_handler.c init_format.c width_handler.c strings_handler.c precision_handler.c ./libft/libft.a