# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aschalh <aschalh@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/31 18:02:44 by aschalh           #+#    #+#              #
#    Updated: 2025/01/31 20:51:46 by aschalh          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

SERVER = server
CLIENT = client

SRC_SERVER = server.c
SRC_CLIENT = client.c

OBJ_SERVER = $(SRC_SERVER:.c=.o)
OBJ_CLIENT = $(SRC_CLIENT:.c=.o)

all: $(SERVER) $(CLIENT)

$(SERVER): $(OBJ_SERVER)
	$(CC) $(CFLAGS) $(OBJ_SERVER) -o $(SERVER)

$(CLIENT): $(OBJ_CLIENT)
	$(CC) $(CFLAGS) $(OBJ_CLIENT) -o $(CLIENT)

clean:
	rm -f $(OBJ_SERVER) $(OBJ_CLIENT)

fclean: clean
	rm -f $(SERVER) $(CLIENT)

re: fclean all

.PHONY: all clean fclean re