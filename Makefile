# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aschalh <aschalh@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/31 18:02:44 by aschalh           #+#    #+#              #
#    Updated: 2025/02/02 16:18:07 by aschalh          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

SERVER = server
CLIENT = client
SERVER_BONUS = server_bonus
CLIENT_BONUS = client_bonus

SRC_SERVER = server.c
SRC_CLIENT = client.c
SRC_SERVER_BONUS = server_bonus.c
SRC_CLIENT_BONUS = client_bonus.c

OBJ_SERVER = $(SRC_SERVER:.c=.o)
OBJ_CLIENT = $(SRC_CLIENT:.c=.o)
OBJ_SERVER_BONUS = $(SRC_SERVER_BONUS:.c=.o)
OBJ_CLIENT_BONUS = $(SRC_CLIENT_BONUS:.c=.o)


all: $(SERVER) $(CLIENT) $(SERVER_BONUS) $(CLIENT_BONUS)

$(SERVER): $(OBJ_SERVER)
	$(CC) $(CFLAGS) $(OBJ_SERVER) -o $(SERVER)

$(CLIENT): $(OBJ_CLIENT)
	$(CC) $(CFLAGS) $(OBJ_CLIENT) -o $(CLIENT)

$(SERVER_BONUS): $(OBJ_SERVER_BONUS)
	$(CC) $(CFLAGS) $(OBJ_SERVER_BONUS) -o $(SERVER_BONUS)

$(CLIENT_BONUS): $(OBJ_CLIENT_BONUS)
	$(CC) $(CFLAGS) $(OBJ_CLIENT_BONUS) -o $(CLIENT_BONUS)

clean:
	rm -rf $(OBJ_SERVER) $(OBJ_CLIENT) $(OBJ_SERVER_BONUS) $(OBJ_CLIENT_BONUS)

fclean: clean
	rm -rf $(SERVER) $(CLIENT) $(SERVER_BONUS) $(CLIENT_BONUS)

re: fclean all

.PHONY: all clean fclean re