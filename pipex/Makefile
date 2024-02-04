# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/17 15:27:14 by myakoven          #+#    #+#              #
#    Updated: 2024/02/04 03:16:53 by myakoven         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= pipex

LIBNAME = libft.a
LIBDIR = ./libft
LIBFT = ./libft/libft.a

#------------------------------------------------#
#   INGREDIENTS                                  #
#------------------------------------------------#

HEADERS 	:= .
SRC     	:= main.c
OBJS     	= $(SRC:.c=.o)

# BONUS		= 
# BONUS_OBJS	= $(BONUS:.c=.o)

CC      	:= cc
CFLAGS  	:= -Wall -Wextra -Werror

#------------------------------------------------#
#   RECIPES                                      #
#------------------------------------------------#

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

makelib:
	make -C $(LIBDIR)
# cp $(LIBDIR)/$(LIBNAME) .
# mv $(LIBNAME) $(NAME)

$(NAME): makelib $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o pipex
# ar -r $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)
	cd $(LIBDIR) && make clean

fclean: clean
	rm -f $(NAME)
	cd $(LIBDIR) && make fclean

re: fclean all

# bonus:	$(OBJS) $(BONUS_OBJS)
# 	ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)

#cc $(CFLAGS) -c $(SRC) -I $(HEADERS)
