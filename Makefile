all:
	gcc -Wall -Wextra -Werror main.c ft_printf.c ft_printf.h flags_handler.c lst_printer.c format_handler.c init_format.c width_handler.c strings_handler.c precision_handler.c size_handler.c type_handler.c string_assembler.c ./builders/c_builder.c ./builders/s_builder.c ./builders/tools.c ./builders/num_tools.c ./builders/di_builder.c ./libft/libft.a