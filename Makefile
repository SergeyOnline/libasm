# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbroderi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/19 19:09:28 by sbroderi          #+#    #+#              #
#    Updated: 2020/10/19 19:09:32 by sbroderi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libasm.a

HEADER = libasm.h

DIR = ./src/

S_FILES = ft_strlen.s \
	ft_strcmp.s \
	ft_strcpy.s \
	ft_strdup.s \
	ft_write.s \
	ft_read.s
	
SRC = $(addprefix $(DIR), $(S_FILES))

ACC = nasm -f macho64
CC = gcc -Wall -Werror -Wextra -O3

OBJ = $(SRC:%.s=%.o)

.PHONY: all, clean, clean, re, test

all: $(NAME) 

$(NAME): $(OBJ)
	
	ar rcs $(NAME) $(OBJ)
	
%.o: %.s ./includes/
	$(ACC) $< -o $@

test: all
	$(CC) main.c $(NAME) -o test

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f test

re: fclean all
