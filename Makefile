# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aschalh <aschalh@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/31 18:02:44 by aschalh           #+#    #+#              #
#    Updated: 2025/02/01 01:13:15 by aschalh          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

SERVER = server
CLIENT = client
UTILS = utils

SRC_SERVER = server.c
SRC_CLIENT = client.c
SRC_UTILS = utils.c

OBJ_SERVER = $(SRC_SERVER:.c=.o)
OBJ_CLIENT = $(SRC_CLIENT:.c=.o)
OBJ_UTILS = $(SRC_CLIENT:.c=.o)

all: $(SERVER) $(CLIENT) $(UTILS)

$(SERVER): $(OBJ_SERVER) $(UTILS)
	$(CC) $(CFLAGS) $(OBJ_SERVER) -o $(SERVER)

$(CLIENT): $(OBJ_CLIENT)
	$(CC) $(CFLAGS) $(OBJ_CLIENT) -o $(CLIENT)

$(UTILS): $(OBJ_UTILS)
	$(CC) $(CFLAGS) $(OBJ_UTILS) -o $(UTILS)

clean:
	rm -f $(OBJ_SERVER) $(OBJ_CLIENT) $(OBJ_UTILS)

fclean: clean
	rm -f $(SERVER) $(CLIENT) $(UTILS)

re: fclean all

.PHONY: all clean fclean re