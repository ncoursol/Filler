# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ncoursol <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/30 19:03:50 by ncoursol          #+#    #+#              #
#    Updated: 2019/09/23 12:10:38 by ncoursol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NO_COLOR = \033[0m
COMP_COLOR = \033[33m
BIN_COLOR = \033[32m
BIN2_COLOR = \033[36m
PROG_COLOR = \033[35m

FILLER_NAME = ncoursol.filler
DISPLAY_NAME = ncoursol.display
MLX = libmlx.a
PTF = libftprintf.a
LIBF= libft.a
CC = gcc
FLAGS = -Wall -Wextra -Werror

LIB_DIR = ./libraries/libft
FT_PRINTF_DIR = ./libraries/ft_printf
MINILIBX_DIR = ./libraries/minilibx_macos
GNL = ./libraries/get_next_line/get_next_line.c

FILLER_SOURCES = ./sources/filler_sources/main.c\
		  		 ./sources/filler_sources/heat_map.c\
		  		 ./sources/filler_sources/filler_algo.c\
				 ./sources/filler_sources/storage.c

DISPLAY_SOURCES = ./sources/display_sources/main.c\
				  ./sources/display_sources/display.c\
				  ./sources/display_sources/color_map.c\
				  ./sources/display_sources/read_vm.c\
				  ./sources/display_sources/storage.c

F_OBJ = $(FILLER_SOURCES:.c=.o)
D_OBJ = $(DISPLAY_SOURCES:.c=.o)

all: $(FILLER_NAME)

$(FILLER_NAME): $(F_OBJ) $(D_OBJ)
	@(cd $(LIB_DIR) && $(MAKE))
	@cp $(LIB_DIR)/libft.a ./libft.a
	@(cd $(FT_PRINTF_DIR) && $(MAKE))
	@cp $(FT_PRINTF_DIR)/libftprintf.a ./libftprintf.a
	@(cd $(MINILIBX_DIR) && $(MAKE))
	@cp $(MINILIBX_DIR)/libmlx.a ./libmlx.a
	@$(CC) -o $(FILLER_NAME) $(F_OBJ) $(PTF) $(LIBF) $(GNL)
	@echo "$(COMP_COLOR)   ---  Filler Compiled !  ---  $(NO_COLOR)"
	@$(CC) -o $(DISPLAY_NAME) -I /usr/local/include $(D_OBJ) -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit $(MLX) $(PTF) $(LIBF) $(GNL)
	@echo "$(COMP_COLOR)   ---  Display Compiled ! ---  $(NO_COLOR)"

clean:
	@rm -rf $(F_OBJ)
	@rm -rf $(D_OBJ)
	@(cd $(LIB_DIR) && $(MAKE) $@)
	@(cd $(FT_PRINTF_DIR) && $(MAKE) $@)
	@(cd $(MINILIBX_DIR) && $(MAKE) $@)
	@rm -Rf $(MLX) $(LIBF) $(PTF)
	@echo "$(BIN2_COLOR)   ---  Binary deleted !   ---        $(NO_COLOR)"

fclean: clean
	@rm -rf $(FILLER_NAME)
	@rm -rf $(DISPLAY_NAME)
	@(cd $(LIB_DIR) && $(MAKE) $@)
	@(cd $(FT_PRINTF_DIR) && $(MAKE) $@)
	@(cd $(MINILIBX_DIR) && $(MAKE) clean)
	@echo "$(PROG_COLOR)   ---  Program deleted !  ---        $(NO_COLOR)"

re: fclean all

.SILENT:

.PHONY: all clean fclean re
