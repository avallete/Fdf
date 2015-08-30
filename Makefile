# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avallete <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/05 12:10:18 by avallete          #+#    #+#              #
#    Updated: 2015/01/06 18:41:20 by avallete         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Sources for compile just if necessary
SRC_PATH=./src/
SRC_NAME=	color_add.c\
			convert_center.c\
			convert_pt.c\
			draw.c\
			grep_arg.c\
			grep_arg2.c\
			isometric.c\
			key_convert.c\
			key_script.c\
			list.c\
			main.c\
			misc.c\
			mod_pts.c\
			print.c\
			print_vertical.c\
			window.c
INC_PATH=./includes/ /opt/X11/include/X11
INC_NAME=	libft.h\
		ft_printf.h\
		X.h\
		mymlx.h
CFLAGS=-Wall -Wextra -Werror
OBJ_PATH =./obj/
OBJ_NAME:=$(SRC_NAME:.c=.o)
SRC:=$(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ:=$(addprefix $(OBJ_PATH), $(OBJ_NAME))
INCF:=$(addprefix $(INC_PATH), $(INC_NAME))
INC:=$(addprefix -I, $(INC_PATH))
LIBMLX=-L/usr/lib64/X11 -lX11 -lXext -L/usr/lib64/ -lmlx
LIBFT=-L libft -lftprintf
CFLAGS= -g
CC=-gcc
NAME=Fdf
RED=\033[0;31m
LBLUE=\033[1;34m
CYAN=\033[0;36m
ORANGE=\033[0;33m
NC=\033[0m

all: $(NAME)

$(NAME):$(OBJ)
	@make -s -C libft
	@echo "${RED}Compile $(NAME) with $(CFLAGS)${NC}";
	@gcc $(CLFAGS) $(OBJ) $(INC) -lm $(LIBMLX) $(LIBFT) -o $(NAME)

$(OBJ_PATH)%.o:$(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@echo "${ORANGE}Create bynary $@ with $<${NC}";
	@$(CC) $(CFLAGS) $(INC) -o $@ -c $<

clean:
	@make clean -C libft
	@rm -f $(OBJ)

fclean: clean
	@echo "${RED}Remove $(NAME)${NC}"
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
