# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/01 17:29:50 by yogun             #+#    #+#              #
#    Updated: 2023/02/02 11:59:01 by yogun            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC:= c++

NAME:= phonebook

FLAGS+= -Wall -Werror -Wextra -std=c++98

SRC:=	Contact.cpp \
		Phonebook.cpp \
		Main.cpp

OBJ:= $(SRC:.cpp=.o)

$(NAME): $(OBJ)
	@ $(CC) $(OBJ) $(FLAGS) -o $(NAME)
	@printf "\nPhonebook compiled \n\n"

all: $(NAME)

clean:
	@rm -f $(OBJ)
	
fclean: clean
	@rm -f $(NAME)

re: fclean
	@make all

.PHONY: clean fclean re