all:
	@gcc -Wall -Wextra -Werror ./server.c ./utils1.c ./utils2.c -o server
	@gcc -Wall -Wextra -Werror ./client.c ./utils1.c ./utils2.c -o client

clean:
	@rm -rf server
	@rm -rf client

fclean: clean

re: fclean all
