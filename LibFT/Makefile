# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myakoven <myakoven@student.42berlin.d      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/17 15:27:14 by myakoven          #+#    #+#              #
#    Updated: 2023/11/17 16:00:50 by myakoven         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= libft.a

#------------------------------------------------#
#   INGREDIENTS                                  #
#------------------------------------------------#

HEADERS := ./includes/
SRC     := ./srcs/ft_putchar.c ./srcs/ft_putstr.c ./srcs/ft_strcmp.c ./srcs/ft_strlen.c ./srcs/ft_swap.c
OBJ     := ft_swap.o ft_putchar.o ft_putstr.o ft_strcmp.o ft_strlen.o

CC      := gcc
CFLAGS  := -Wall -Wextra -Werror

#------------------------------------------------#
#   RECIPES                                      #
#------------------------------------------------#

all: $(NAME)

$(NAME):
	gcc $(CFLAGS) -c $(SRC) -I $(HEADERS)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f *.o

fclean: clean
	rm $(NAME)

re: 
	$(MAKE) fclean 
	$(MAKE) all
