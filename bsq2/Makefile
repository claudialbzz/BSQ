NAME = bsq

<<<<<<< HEAD
SRCS = src/main.c src/error.c src/map1.c src/solve.c src/print.c src/map2.c
=======
SRCS = src/main.c src/error.c src/map.c src/solve.c src/print.c src/alg.c
>>>>>>> 3144a69 (Por fin la fokin' norminette)
OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re