# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ksellami <ksellami@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/17 14:44:30 by ksellami          #+#    #+#              #
#    Updated: 2024/05/17 14:44:30 by ksellami         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
NAME = minitalk
FLAGS = -Wall -Wextra -Werror
RMV = rm -rf
HEADER = minitalk.h

SRC_UTILS= utils.c
utils_obj = $(SRC_UTILS:.c=.o)

SRC_S = server.c
SRC_C = client.c

client_obj = $(SRC_C:.c=.o)
server_obj = $(SRC_S:.c=.o)

$(NAME): $(utils_obj) $(client_obj) $(server_obj)
	$(CC) $(CFLAGS) $(utils_obj) $(server_obj)  -o server
	$(CC) $(CFLAGS) $(utils_obj) $(client_obj)  -o client
	
all : $(NAME)
%.o:%.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	$(RMV) $(client_obj) $(server_obj)  $(utils_obj)

fclean: clean
	 $(RMV) client server 

re : fclean $(NAME)
