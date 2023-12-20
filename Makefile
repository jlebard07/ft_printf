# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jlebard <jlebard@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/20 13:41:45 by jlebard           #+#    #+#              #
#    Updated: 2023/12/20 16:31:19 by jlebard          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

WINDOWS = no
NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = sources/printf_hexa.c souces/printf_hexa2.c sources/printf_ptr.c \
sources/printf_str.c sources/printf_unsigned.c ft_ptintf.c
OBJ = $(SRC:.c=.o)
AR = ar rcs

ifeq ($(WINDOWS), yes)
	CLEAN = del /Q
	FCLEAN = del /Q
else 
	CLEAN = rm -rf 
	FCLEAN = rm -f
endif

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@
$(NAME): $(OBJS)
	$(MAKE) -C ./libft
	cp libft/libft.a $(NAME)
	ar rc $(NAME) $(OBJS)

all: $(NAME)

clean:
	$(CLEAN) libft/*.o

fclean: clean
	$(FCLEAN) $(NAME)
	$(FCLEAN) libft/libft.a

re: fclean all

