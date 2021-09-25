# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skienzle <skienzle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/18 11:59:49 by skienzle          #+#    #+#              #
#    Updated: 2021/09/19 20:43:00 by skienzle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
CC = gcc
CFLAGS = -O3 -Lmlx -lmlx -framework OpenGL -framework AppKit # -Wall -Werror -Wextra
RM = rm -rf

ODIR = ./objs
LIBFT = ./libft/libft.a

SRC = srcs/main.c
OBJ = $(ODIR)/*.o

$(NAME): $(SRC) ./includes/fractol.h
	make -C ./libft
	$(CC) $(CFLAGS) -c $(SRC)
	$(RM) $(ODIR) && mkdir $(ODIR)
	mv *.o $(ODIR)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

all: $(NAME)

clean:
	$(RM) $(ODIR)
	cd ./libft && make clean

fclean: clean
	$(RM) $(NAME)
	cd ./libft && make fclean

re: fclean all

bonus: $(NAME)

.PHONY: all clean fclean re bonus
