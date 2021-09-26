# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skienzle <skienzle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/18 11:59:49 by skienzle          #+#    #+#              #
#    Updated: 2021/09/26 20:48:43 by skienzle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
CC = gcc
CFLAGS = -O3 -Wall -Werror -Wextra
MLX_FLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit
RM = rm -rf

ODIR = ./objs
LIBFT = ./libft/libft.a

SRC = srcs/init.c srcs/conversion.c srcs/colour.c srcs/fractols.c \
	srcs/window.c srcs/mouse.c srcs/keys.c srcs/useage.c srcs/main.c
OBJ = $(ODIR)/*.o

$(NAME): $(SRC) ./includes/fractol.h
	make -C ./mlx
	make -C ./libft
	$(CC) $(CFLAGS) -c $(SRC)
	$(RM) $(ODIR) && mkdir $(ODIR)
	mv *.o $(ODIR)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX_FLAGS) -o $(NAME)

all: $(NAME)

clean:
	$(RM) $(ODIR)
	cd ./mlx && make clean
	cd ./libft && make clean

fclean: clean
	$(RM) $(NAME)
	cd ./libft && make fclean

re: fclean all

bonus: $(NAME)

.PHONY: all clean fclean re bonus
