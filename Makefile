# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sleung <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/01 10:15:53 by sleung            #+#    #+#              #
#    Updated: 2017/03/15 14:28:00 by sleung           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: clean fclean all index re

NAME = libft.a
CC = gcc
CFLAGS = -c -Wall -Werror -Wextra

INC_DIR =  ./includes
SRC_DIR = ./srcs
OBJ_DIR = ./obj

-include sources.mk

INC = $(addprefix -I , $(INC_DIR))
SRCS = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJS = $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))

all: $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $< -o $@ $(INC)

$(NAME): $(OBJS)
	@echo "\x1B[36m*** Compilation successfully finished ***\033[0m"
	ar rc $(NAME) $(OBJS)
	@echo "\x1B[33m*** Library successfully archived ***\033[0m"
	ranlib $(NAME)

clean:
	@echo "\x1B[35m***** Cleaning object files *****\033[0m"
	rm -rf $(OBJ_DIR)

fclean: clean
	@echo "\x1B[32m***** Deep cleaning of Library *****\033[0m"
	rm -f $(NAME)

re: fclean all
