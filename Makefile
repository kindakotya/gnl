# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmayweat <gmayweat@42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/02 12:32:44 by gmayweat          #+#    #+#              #
#    Updated: 2020/12/02 13:57:45 by gmayweat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line

SRCS = 	$(NAME).c $(NAME)_utils.c	main.c

HEAD = $(NAME).h

OBJS = $(SRCS:.c=.o)

.Phony: all $(NAME) clean re fclean .o.c

all: $(NAME)

$(NAME): $(OBJS)
		clang -g -Wall -Wextra -Werror $(OBJS) -o $(NAME)

%.o: %.c
		clang -g -Wall -Wextra -Werror -D BUFFER_SIZE=50 -c $<

clean:
		rm -rf $(OBJS)

fclean: clean
		rm -rf $(NAME)

re: fclean all