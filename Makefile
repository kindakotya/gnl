NAME = get_next_line

SRCS = 	$(NAME).c $(NAME)_utils.c	main.c

HEAD = $(NAME).h

OBJS = $(SRCS:.c=.o)

.Phony: all $(NAME) clean re fclean .o.c

all: $(NAME)

$(NAME): $(OBJS)
		gcc -g -Wall -Wextra -Werror $(OBJS) -o $(NAME)

%.o: %.c
		gcc -g -Wall -Wextra -Werror -D BUFFER_SIZE=50 -c $<

clean:
		rm -rf $(OBJS)

fclean: clean
		rm -rf $(NAME)

re: fclean all