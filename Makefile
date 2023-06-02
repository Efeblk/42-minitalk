SERVER = server
CLIENT = client
PRINTF = printf

CFLAGS = -Wall -Werror -Wextra
CC = gcc

all:
	
	@gcc $(FLAGS) server.c -o $(SERVER)
	@gcc $(FLAGS) client.c -o $(CLIENT)
	@echo "Server And Client Are Ready!"

clean:
fclean: clean
	
	@rm -f $(SERVER) $(CLIENT)
	@echo "Server and Client Have Been Cleaned Successfully"

re: fclean all