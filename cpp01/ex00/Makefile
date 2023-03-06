# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/02 12:06:55 by yogun             #+#    #+#              #
#    Updated: 2023/03/06 15:45:24 by yogun            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Declare the compiler to use
CC = g++

# Flags for the compiler
CFLAGS = -Wall -Wextra -Werror

# Source files for the project
SRCS = main.cpp Zombie.cpp newZombie.cpp randomChump.cpp

# Object files generated from source files
OBJS = $(SRCS:.cpp=.o)

# Name of the executable to generate
NAME = zombie

# Colors for console messages
GREEN = \033[0;32m
RED = \033[0;31m
YELLOW = \033[0;33m
RESET = \033[0m

# Make rules
all: $(NAME)
	@echo "$(GREEN)👍 Compiled successfully!$(RESET)"

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(YELLOW)🛠️ Compiling $<...$(RESET)"

clean:
	@rm -f $(OBJS)
	@echo "$(RED)🗑️ Cleaned object files.$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)🗑️ Cleaned executable.$(RESET)"

re: fclean all

.PHONY: clean fclean re