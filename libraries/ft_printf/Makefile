# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ncoursol <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/30 19:03:50 by ncoursol          #+#    #+#              #
#    Updated: 2019/09/23 12:23:23 by ncoursol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NO_COLOR = \033[0m
COMP_COLOR = \033[33m
BIN_COLOR = \033[32m
BIN2_COLOR = \033[36m
PROG_COLOR = \033[35m

NAME = libftprintf.a
CC = gcc
FLAGS = -Wall -Wextra -Werror

LIB_DIR = ../libft

SOURCES = ft_format_csp.c\
ft_format_di.c\
ft_nan_inf.c\
ft_print_float.c\
ft_format_f.c\
ft_format_u.c\
ft_format_xx.c\
ft_check_add.c\
ft_check_char.c\
ft_convert.c\
ft_printf.c\
ft_ltoa.c\
ft_ftoa.c\
ft_utoa.c\
ft_dtoh.c\
ft_format_pct.c\
ft_format_b.c\
ft_format_o.c\
ft_color.c\
ft_float.c\
ft_mult2.c\


OBJ = $(SOURCES:.c=.o)

INCLUDE = ft_printf.h

$(NAME): $(OBJ)
	@$(CC) $(FLAGS) -c $(SOURCES)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

all: $(NAME)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

:x

.PHONY: all clean fclean re
