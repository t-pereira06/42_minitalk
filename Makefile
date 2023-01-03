# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsodre-p <tsodre-p@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/02 14:26:29 by tsodre-p          #+#    #+#              #
#    Updated: 2023/01/03 15:48:40 by tsodre-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT = libft/libft.a

CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

CLIENT = client
SERVER = server

SRC_CLIENT = srcs/client.c
OBJ_CLIENT = $(SRC_CLIENT:%.c=%.o)

SRC_SERVER = srcs/server.c
OBJ_SERVER = $(SRC_SERVER:%.c=%.o)

all: $(SERVER) $(CLIENT)

$(LIBFT):
	@$(MAKE) -C ./libft

$(SERVER): $(OBJ_SERVER) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJ_SERVER) $(LIBFT) -o server

$(CLIENT): $(OBJ_CLIENT) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJ_CLIENT) $(LIBFT) -o client

clean:
		@$(MAKE) fclean -C ./libft
		@$(RM) $(OBJ_SERVER) $(OBJ_CLIENT)

fclean: clean
		@$(MAKE) fclean -C ./libft
		@$(RM) $(SERVER) $(CLIENT)

re: fclean all
