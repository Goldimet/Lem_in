# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rkamegne <rkamegne@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/22 17:12:26 by rkamegne          #+#    #+#              #
#    Updated: 2019/06/29 15:47:16 by rkamegne         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN=\033[1;32m

RED=\033[1;31m

BLACK=\033[0m

CC = gcc

CFLAGS=-Wall -Wextra -Werror

NAME = lem-in

INCLUDES = -I libft/ -I inc/

LIB = -L libft/ -lft
LIBFT_PATH = libft/

SRC = src/main.c src/ft_check_line.c src/ft_utils.c

OBJ = $(addprefix obj/, $(patsubst %.c, %.o, $(SRC)))

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIBFT_PATH)
	$(CC) -o $@ $^ $(LIB)
	@echo "\n$(GREEN)[$(NAME) created]$(BLACK)"

clean:
	make -C $(LIBFT_PATH) clean
	rm -rf $(OBJ)
	@echo "\n$(RED)[.o deleted]$(BLACK)"

fclean: clean
	make -C $(LIBFT_PATH) fclean
	rm -rf $(NAME)
	@echo "\n$(RED)[$(NAME) deleted]$(BLACK)"

re: fclean all

obj/%.o:%.c
	@mkdir -p obj/src
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

.PHONY: all clean fclean re
