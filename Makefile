# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bkaztaou <bkaztaou@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/10 01:00:34 by bkaztaou          #+#    #+#              #
#    Updated: 2023/07/10 01:39:47 by bkaztaou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CNAME = client
SNAME = server
CC = cc
CFLAGS = -Wall -Wextra -Werror

CFILES = client.c ft_atoi.c
SFILES = server.c

COBJ = $(CFILES:.c=.o)
SOBJ = $(SFILES:.c=.o)

RM = rm -rf

all: $(CNAME) $(SNAME)

$(CNAME): $(COBJ)
		$(CC) $(CFLAGS) -o $(CNAME) $(COBJ)

$(SNAME): $(SOBJ)
		$(MAKE) -C ./ft_printf
		$(CC) $(CFLAGS) -o $(SNAME) $(SOBJ) -Lft_printf -lftprintf

clean:
		$(MAKE) -C ./ft_printf fclean
		$(RM) $(SOBJ) $(COBJ)

fclean: clean
		$(RM) $(SNAME) $(CNAME)

re: fclean all

.PHONY: all clean fclean re
