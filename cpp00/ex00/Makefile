# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/27 14:31:26 by yogun             #+#    #+#              #
#    Updated: 2023/01/27 14:36:50 by yogun            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC:= c++

NAME:= megaphone

FLAGS+= -Wall -Werror -Wextra -std=c++98

SRC:=	megaphone.cpp

OBJECTS:=  $(SRC:c=o)

$(NAME): $(OBJECTS)
	@$(CC) $(OBJECTS) $(FLAGS) -o $(NAME)
	@printf "\nMegaphone compiled \n\n"

%.o: %.c
	$(CC) $< -c $(FLAGS) -o $(NAME)

all: $(NAME)

clean:
	@rm -f $(OBJECTS)

fclean: clean
	@rm -f $(NAME)

re: fclean
	@make all

.PHONY: clean fclean re