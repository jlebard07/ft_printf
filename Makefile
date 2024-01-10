# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jlebard <jlebard@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/20 13:41:45 by jlebard           #+#    #+#              #
#    Updated: 2024/01/03 13:35:40 by jlebard          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

WINDOWS = no
NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = sources/printf_hexa.c sources/printf_hexa2.c sources/printf_ptr.c \
sources/printf_str.c sources/printf_unsigned.c ft_printf.c sources/printf_decimal.c
OBJS = $(SRC:.c=.o)
AR = ar rcs

ifeq ($(WINDOWS), yes)
	CLEAN = del /Q
	FCLEAN = del /Q
else 
	CLEAN = rm -rf
	FCLEAN = rm -f
endif

%.o : %.c
	$(CC) $(CCFLAGS) -c -o $@ $<
	
$(NAME): $(OBJS)
	$(MAKE) -C ./libft
	cp libft/libft.a $(NAME)
	$(AR) $(NAME) $(OBJS)

all: $(NAME)

clean:
	$(CLEAN) libft/*.o
	$(CLEAN) sources/*.o
	$(CLEAN) ft_printf.o

fclean: clean
	$(FCLEAN) $(NAME)
	$(FCLEAN) libft/libft.a

re: fclean all

.PHONY: all clean fclean re
