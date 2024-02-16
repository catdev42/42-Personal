# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/17 15:27:14 by myakoven          #+#    #+#              #
#    Updated: 2024/02/17 00:51:21 by myakoven         ###   ########.fr        #
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
SRC     	:= pipex.c pipex_utils.c
OBJS     	= $(SRC:.c=.o)

SRCBONUS	:= ./pipex_bonus/pipex_bonus.c ./pipex_bonus/pipex_bonus.h ./pipex_bonus/pipex_utils_bonus.c
OBJSBONUS	:= $(SRCBONUS:.c=.o)

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

$(LIBFT):
	make -C $(LIBDIR)
# cp $(LIBDIR)/$(LIBNAME) .
# mv $(LIBNAME) $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o pipex
# ar -r $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)
	cd $(LIBDIR) && make clean

fclean: clean
	rm -f $(NAME)
	cd $(LIBDIR) && make fclean

re: fclean all

bonus: fclean $(LIBFT) $(OBJSBONUS)
	$(CC) $(CFLAGS) $(OBJSBONUS) $(LIBFT) -o $(NAME)

# bonus:	$(OBJS) $(BONUS_OBJS)
# 	ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)

#cc $(CFLAGS) -c $(SRC) -I $(HEADERS)
