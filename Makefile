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
SRC:=src/color_add.c\
	src/convert_center.c\
	src/convert_pt.c\
	src/draw.c\
	src/grep_arg.c\
	src/grep_arg2.c\
	src/isometric.c\
	src/key_convert.c\
	src/key_script.c\
	src/list.c\
	src/main.c\
	src/misc.c\
	src/mod_pts.c\
	src/print.c\
	src/print_vertical.c\
	src/window.c
INCF:=	includes/libft.h\
		includes/get_next_line.h\
		includes/mymlx.h
LIBFTSRC=libft/ft_realloc.c libft/ft_atoi.c libft/ft_bzero.c libft/ft_isalnum.c libft/ft_isalpha.c libft/ft_isascii.c libft/ft_isdigit.c libft/ft_isprint.c libft/ft_itoa.c libft/ft_lstadd.c libft/ft_lstdel.c libft/ft_lstdelone.c libft/ft_lstiter.c libft/ft_lstmap.c libft/ft_lstnew.c libft/ft_memalloc.c libft/ft_memccpy.c libft/ft_memchr.c libft/ft_memcmp.c libft/ft_memcpy.c libft/ft_strndup.c libft/ft_memdel.c libft/ft_memmove.c libft/ft_memset.c libft/ft_putchar.c libft/ft_putchar_fd.c libft/ft_putendl.c libft/ft_putnbr.c libft/ft_putnbr_fd.c libft/ft_putstr.c libft/ft_putstr_fd.c libft/ft_strcat.c libft/ft_strchr.c libft/ft_strclr.c libft/ft_strcmp.c libft/ft_strcpy.c libft/ft_strdel.c libft/ft_strdup.c libft/ft_strequ.c libft/ft_striter.c libft/ft_striteri.c libft/ft_strjoin.c libft/ft_strlcat.c libft/ft_strlen.c libft/ft_strmap.c libft/ft_strmapi.c libft/ft_strncat.c libft/ft_strncmp.c libft/ft_strncpy.c libft/ft_strnew.c libft/ft_strnstr.c libft/ft_strrchr.c libft/ft_strsplit.c libft/ft_strstr.c libft/ft_strsub.c libft/ft_strtrim.c libft/ft_tolower.c libft/ft_toupper.c libft/ft_calloc.c libft/ft_lstpushback.c libft/ft_lstsize.c libft/ft_lstlast.c libft/ft_treenew.c libft/ft_nodeaddleft.c libft/ft_nodeaddright.c libft/get_next_line.c
OBJ:=$(SRC.c=.o)

# Options can be changed

CFLAGS=-Wall -Wextra -Werror
CC=gcc
NAME=fdf

# Includes lib

LIBMLX:=-L /usr/X11/lib -lmlx -lXext -lX11
LIBFT:=-L libft -lft
INC:=includes/

# Sweet colors just for swag :)

RED=\033[0;31m
LBLUE=\033[1;34m
CYAN=\033[0;36m
ORANGE=\033[0;33m
NC=\033[0m

all: $(NAME)

$(NAME): $(SRC) $(INCF) $(LIBFTSRC)
	@make -s -C libft
	@echo "${LBLUE}Compile fdf${NC}"
	@$(CC) $(CFLAGS) $(SRC) $(LIBMLX) $(LIBFT) -I $(INC) -o $(NAME)

clean:
	@make clean -C libft
	@rm -f $(OBJ)

fclean: clean
	@echo "${RED}Remove $(NAME)${NC}"
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
