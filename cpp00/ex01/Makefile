# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/01 17:29:50 by yogun             #+#    #+#              #
#    Updated: 2023/02/01 23:51:28 by yogun            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC:= c++

NAME:= phonebook

FLAGS+= -Wall -Werror -Wextra -std=c++98

SRC:=	Contact.cpp \
		Phonebook.cpp \
		Main.cpp

$(NAME):
	@ $(CC) $(SRC) $(FLAGS) -o $(NAME)
	@printf "\nPhonebook compiled \n\n"

all: $(NAME)

fclean:
	@rm -f $(NAME)

re: fclean
	@make all

.PHONY: fclean re