# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: miwasa <miwasa@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/21 12:39:52 by miwasa            #+#    #+#              #
#    Updated: 2024/09/22 13:20:13 by miwasa           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rush-02

SRCS = ft_is_valid_arg.c \
	   ft_is_vaild_num.c \
	   ft_is_valid_dict.c \
	   ft_handle_zero.c \
	   ft_print.c \
	   ft_read_dict.c \
	   ft_convert_num_to_words.c \
	   ft_convert_num_to_words2.c \
	   ft_convert_num_to_words3.c \
	   ft_find_word.c \
	   ft_free_entries.c \
	   ft_into_entry.c \
	   ft_into_entry2.c \
	   ft_split.c \
	   ft_strcmp.c \
	   ft_strdup.c \
	   ft_strjoin.c \
	   main.c

CC = cc
CFLAGS = -Wall -Wextra -Werror

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
