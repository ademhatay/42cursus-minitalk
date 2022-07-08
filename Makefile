NAME = minitalk.a

FLAG = -Wall -Wextra -Werror

CC = gcc

all:
	$(CC) $(FLAG) ./server.c ./utils1.c ./utils2.c -o server
	$(CC) $(FLAG) ./client.c ./utils1.c ./utils2.c -o client

clean:
	rm -rf server
	rm -rf client

fclean: clean

re: fclean all
