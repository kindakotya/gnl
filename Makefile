# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmayweat <gmayweat@42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/02 12:32:44 by gmayweat          #+#    #+#              #
#    Updated: 2020/12/29 15:00:19 by gmayweat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line

SRCS = 				$(NAME).c\
					$(NAME)_utils.c\
					main.c

HEAD = $(NAME).h

vpath %.o obj

OBJS = $(SRCS:.c=.o)

OBJSPATH = $(addprefix obj/, $(OBJS))

OBJSDIR = obj

.Phony: all $(NAME) clean re fclean

all: $(NAME)

$(NAME): $(OBJSDIR) $(OBJS)
	clang -g -Wall -Wextra -Werror $(OBJSPATH) -o $(NAME)

%.o: %.c $(HEAD)
	clang -g -Wall -Wextra -Werror -D BUFFER_SIZE=10 -o $(addprefix obj/, $(patsubst %.c, %.o, $<)) -c $<

$(OBJSDIR):
	mkdir obj

clean:
	rm -rf objs

fclean: clean
	rm -rf $(NAME)

re: fclean $(CREAT_OBJSDIR) all
