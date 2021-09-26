# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skienzle <skienzle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/15 16:50:07 by skienzle          #+#    #+#              #
#    Updated: 2021/09/26 20:52:52 by skienzle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

SRCS = ft_isdigit.c ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c \
	ft_isalpha.c ft_isascii.c ft_isprint.c ft_itoa.c ft_memchr.c \
	ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c \
	ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c \
	ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c \
	ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c \
	ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c \
	ft_atof.c \
	get_next_line_bonus.c get_next_line_utils_bonus.c \
	ft_printers.c ft_printf.c

OBJS = $(SRCS:.c=.o)

BSRCS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
	ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

BOBJS = $(BSRCS:.c=.o)

$(NAME): libft.h $(SRCS) $(BSRCS)
	$(CC) $(CFLAGS) -c $(SRCS) $(BSRCS)
	ar -rc $(NAME) $(OBJS) $(BOBJS)
	ranlib $(NAME)

all: $(NAME)

clean: 
	$(RM) $(OBJS) $(BOBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean bonus

bonus: libft.h $(SRCS) $(BSRCS)
	$(CC) $(CFLAGS) -c $(SRCS) $(BSRCS)
	ar -rc $(NAME) $(OBJS) $(BOBJS)
	ranlib $(NAME)

.PHONY: all clean fclean re bonus