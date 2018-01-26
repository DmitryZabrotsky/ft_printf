# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dzabrots <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/22 21:23:41 by dzabrots          #+#    #+#              #
#    Updated: 2017/11/27 19:51:40 by dzabrots         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC = ft_lstprint.c	ft_striter.c ft_striteri.c \
	  ft_memalloc.c ft_strjoin.c ft_atoi.c \
	  ft_memccpy.c ft_strlcat.c ft_memchr.c \
	  ft_strlen.c ft_atoll.c ft_memcmp.c ft_strmap.c ft_bzero.c	\
	  ft_memcpy.c ft_strmapi.c ft_isalnum.c	ft_memdel.c	ft_strncat.c \
	  ft_isalpha.c ft_memmove.c	ft_strncmp.c ft_isascii.c ft_memset.c \
	  ft_strncpy.c ft_isdigit.c ft_putchar.c ft_strnequ.c ft_isprint.c \
	  ft_putchar_fd.c ft_strnew.c ft_itoa.c ft_putendl.c ft_strnstr.c \
	  ft_putendl_fd.c ft_strrchr.c ft_lstadd.c ft_putnbr.c \
	  ft_putnbr_fd.c ft_strcspn.c ft_lstlen.c \
	  ft_putstr.c	ft_strsplit.c ft_lstdel.c ft_putstr_fd.c \
	  ft_lstdelone.c ft_strcat.c ft_strstr.c ft_lstaddend.c \
	  ft_strchr.c ft_strsub.c ft_strclr.c ft_arrtolst.c \
	  ft_strtrim.c ft_lstiter.c ft_strcmp.c ft_tolower.c  \
	  ft_strcpy.c ft_toupper.c ft_lstmap.c ft_strdel.c \
	  ft_lstnew.c ft_strdup.c ft_strequ.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

%.o: %.c 
	$(CC) -c $(CFLAGS) $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
