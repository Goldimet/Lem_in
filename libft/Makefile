# **************************************************************************** #
#                                                                      #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rkamegne <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/18 18:23:24 by rkamegne          #+#    #+#              #
#    Updated: 2019/06/29 21:19:10 by rkamegne         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC = ft_lstdel.c ft_putendl_fd.c ft_strdel.c ft_strnequ.c ft_atoi.c ft_lstdelone.c\
	ft_putnbr.c ft_strdup.c ft_strnew.c ft_atoi_base.c ft_lstiter.c ft_putnbr_fd.c\
	ft_strdup_at.c ft_strnstr.c ft_bzero.c ft_lstmap.c ft_putstr.c ft_strequ.c\
	ft_strrchr.c ft_cislower.c ft_lstnew.c ft_putstr_fd.c ft_striter.c ft_strsplit.c\
	ft_cisspace.c ft_memalloc.c ft_replace.c ft_striteri.c ft_strstr.c ft_cisupper.c\
	ft_memccpy.c ft_sqrt.c ft_strjoin.c ft_strsub.c ft_count_words.c ft_memchr.c\
	ft_str_putchar.c ft_strjoin_free.c ft_strtrim.c ft_isalnum.c ft_memcmp.c\
	ft_strcat.c ft_strlcat.c ft_tolower.c ft_isalpha.c ft_memcpy.c ft_strcat_free.c\
	ft_strlen.c ft_toupper.c ft_isascii.c ft_memdel.c ft_strccpy.c ft_strlen_err.c\
	ft_utoa_base.c ft_isdigit.c ft_memmove.c ft_strchr.c ft_strmap.c get_next_line.c\
	ft_ispace.c ft_memset.c ft_strchr_alpha.c ft_strmapi.c ft_isprint.c ft_putchar.c\
	ft_strclr.c ft_strncat.c ft_itoa.c ft_putchar_fd.c ft_strcmp.c ft_strncmp.c ft_lstadd.c\
	ft_putendl.c ft_strcpy.c ft_strncpy.c ft_conver_csp.c ft_printf.c ft_parse.c ft_utils.c\
	ft_conver_numbers.c ft_unsigned_numbers.c ft_unsigned_numbers2.c ft_float_numbers.c ft_lstaddback.c\
	ft_lstlen.c ft_free_content.c ft_isnumber.c ft_error.c

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror

CC = gcc

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) -c $(SRC)
	@ar -rc $(NAME) $(OBJ)
	@ranlib $(NAME)


clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY : fclean clean all re
