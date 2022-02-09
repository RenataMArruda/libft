# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: rarruda <marvin@codam.nl>                    +#+                      #
#                                                    +#+                       #
#    Created: 2020/11/18 12:45:30 by rarruda       #+#    #+#                  #
#    Updated: 2021/01/15 13:07:03 by rarruda       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_atof.c\
		ft_atoi.c\
		ft_bzero.c\
		ft_calloc.c\
		ft_const_strlen.c\
		ft_isalnum.c\
		ft_isalpha.c\
		ft_isascii.c\
		ft_isdigit.c\
		ft_isprint.c\
		ft_itoa.c\
		ft_long_atoi.c\
		ft_memccpy.c\
		ft_memchr.c\
		ft_memcmp.c\
		ft_memcpy.c\
		ft_memmove.c\
		ft_memset.c\
		ft_power.c\
		ft_putchar.c\
		ft_putchar_fd.c\
		ft_putendl_fd.c\
		ft_puthex.c\
		ft_putnbr.c\
		ft_putnbr_fd.c\
		ft_putpoi.c\
		ft_putstr.c\
		ft_putstr_fd.c\
		ft_putunsnbr.c\
		ft_split.c\
		ft_strchr.c\
		ft_strdup.c\
		ft_strjoin.c\
		ft_strlcat.c\
		ft_strlcpy.c\
		ft_strlen.c\
		ft_strmapi.c\
		ft_strncmp.c\
		ft_strnstr.c\
		ft_strrchr.c\
		ft_strtrim.c\
		ft_substr.c\
		ft_tolower.c\
		ft_toupper.c

OBJ = $(SRC:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
