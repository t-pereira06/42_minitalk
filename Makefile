# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsodre-p <tsodre-p@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/02 14:26:29 by tsodre-p          #+#    #+#              #
#    Updated: 2023/01/09 09:58:12 by tsodre-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT = libft/libft.a

CC = cc
RM = rm -rf

CLIENT = client
SERVER = server
CLIENT_BONUS = client_bonus
SERVER_BONUS = server_bonus

SRC_CLIENT = srcs/client.c
OBJ_CLIENT = $(SRC_CLIENT:%.c=%.o)

SRC_SERVER = srcs/server.c
OBJ_SERVER = $(SRC_SERVER:%.c=%.o)

SRC_CLIENT_BONUS = srcs_bonus/client_bonus.c
OBJ_CLIENT_BONUS = $(SRC_CLIENT_BONUS:%.c=%.o)

SRC_SERVER_BONUS = srcs_bonus/server_bonus.c
OBJ_SERVER_BONUS = $(SRC_SERVER_BONUS:%.c=%.o)

all: $(SERVER) $(CLIENT) $(SERVER_BONUS) $(CLIENT_BONUS)

$(LIBFT):
	@$(MAKE) -C ./libft

$(SERVER): $(OBJ_SERVER) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJ_SERVER) $(LIBFT) -o server

$(CLIENT): $(OBJ_CLIENT) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJ_CLIENT) $(LIBFT) -o client

$(SERVER_BONUS): $(OBJ_SERVER_BONUS) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJ_SERVER_BONUS) $(LIBFT) -o server_bonus

$(CLIENT_BONUS): $(OBJ_CLIENT_BONUS) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJ_CLIENT_BONUS) $(LIBFT) -o client_bonus

clean:
		@$(MAKE) fclean -C ./libft
		@$(RM) $(OBJ_SERVER) $(OBJ_CLIENT) $(OBJ_SERVER_BONUS) $(OBJ_CLIENT_BONUS)

fclean: clean
		@$(MAKE) fclean -C ./libft
		@$(RM) $(SERVER) $(CLIENT) $(SERVER_BONUS) $(CLIENT_BONUS)

re: fclean all
