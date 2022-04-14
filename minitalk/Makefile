NAME = $(cl) $(srv)

NAME_b = $(cl_bonus) $(srv_bonus)

client_bonus = minitalk_bonus/client_bonus.c

server_bonus = minitalk_bonus/server_bonus.c

client = minitalk/client.c

server = minitalk/server.c

cl = client

srv = server

cl_bonus = client_bonus

srv_bonus = server_bonus

utils_bonus = minitalk_bonus/utils_bonus.c

utils = minitalk/utils.c

SRC_b = minitalk_bonus/server_bonus.c minitalk_bonus/client_bonus.c minitalk_bonus/utils_bonus.c

SRC = minitalk/server.c minitalk/client.c minitalk/utils.c

obj = $(SRC:.c=.o)

obj_b = $(SRC_b:.c=.o)

hd_bonus =  minitalk_bonus/minitalk_bonus.h

hd =  minitalk/minitalk.h

flags = -Wall -Wextra -Werror


all : $(NAME)

$(NAME) : $(hd) $(obj) $(SRC)
	cc $(flags) $(server) $(utils) -o $(srv) 
	cc $(flags) $(client) $(utils) -o $(cl)

bonus : $(NAME_b)

$(NAME_b) : $(hd_bonus) $(obj_b) $(SRC_b)
	cc $(flags) $(server_bonus) $(utils_bonus) -o $(srv_bonus)
	cc $(flags) $(client_bonus) $(utils_bonus) -o $(cl_bonus)

%.o : %.c
	cc $(flags) -c $< -o $@

clean :
	rm -rf $(obj) $(obj_b)

fclean : clean 
	rm -f $(srv) $(cl) $(srv_bonus) $(cl_bonus)

re : fclean all
