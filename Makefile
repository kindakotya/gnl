# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmayweat <gmayweat@42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/02 12:32:44 by gmayweat          #+#    #+#              #
#    Updated: 2020/12/29 11:33:14 by gmayweat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line

SRCS = 	$(NAME).c $(NAME)_utils.c	main.c

HEAD = $(NAME).h

vpath %.o objs

OBJS = $(SRCS:.c=.o)

OBJSPATH = $(addprefix objs/, $(OBJS))

OBJSDIR = objs

.Phony: all $(NAME) clean re fclean

all: $(NAME)

$(NAME): $(OBJSDIR) $(OBJS)
	clang -g -Wall -Wextra -Werror $(OBJSPATH) -o $(NAME)

%.o: %.c $(HEAD)
	clang -g -Wall -Wextra -Werror -D BUFFER_SIZE=99999 -o $(addprefix objs/, $(patsubst %.c, %.o, $<)) -c $<

$(OBJSDIR):
	mkdir objs

clean:
	rm -rf objs

fclean: clean
	rm -rf $(NAME)

re: fclean $(CREAT_OBJSDIR) all
