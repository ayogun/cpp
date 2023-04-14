# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/07 14:30:54 by yogun             #+#    #+#              #
#    Updated: 2023/04/14 16:17:41 by yogun            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Colors
GREEN = \033[1;32m
CYAN = \033[1;36m
YELLOW = \033[1;33m
RESET = \033[0m
RED = \033[0;31m

# Set the compiler to use
CC = c++
# Set the compiler flags to use
CFLAGS = -Wall -Werror -Wextra -std=c++98

# Set the name of the executable to create
NAME = PmergeMe

# Set the source files to compile
SRC = main.cpp PmergeMe.cpp

# Generate a list of object files from the source files
OBJ = $(SRC:.cpp=.o)

# The default target to build
all: $(NAME)

# Target to build the executable
$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) # Compile the executable with the object files
	@echo "$(GREEN)🚀 Successfully compiled! 🎉$(RESET)" # Display a colorful message indicating success

# Target to compile a single source file into an object file
%.o: %.cpp
	@$(CC) $(CFLAGS) -c $< -o $@ # Compile the source file into an object file
	@echo "$(YELLOW)🔨 Compiling $< ...$(RESET)" # Display a colorful message indicating which file is being compiled

# Target to clean the object files
clean:
	@rm -f $(OBJ) # Remove all object files
	@echo "$(RED)🧹 Cleaned object files.$(RESET)" 

# Target to clean the object files and the executable
fclean: clean
	@rm -f $(NAME) # Remove the executable file
	@echo "$(RED)🧹 Cleaned object files and executable.$(RESET)" 

# Target to clean and rebuild the executable
re: remsg fclean all

remsg: 
	@echo "$(CYAN)🔁 Rebuilding...$(RESET)"

test:
	@echo "$(CYAN)🔁 Testing...$(RESET)"
	@echo "__________ TEST-1 _____________ , 5 NUMBERS"
	./$(NAME) 3 5 9 7 4
	@echo
	@echo "__________ TEST-2 ______________ , 50 NUMBERS"
	./$(NAME) `jot -r 50 10000000 99999999`
	@echo
	@echo "__________ TEST-3 ______________ , 100 NUMBERS"
	./$(NAME) `jot -r 100 10000000 99999999`
	@echo
	@echo "__________ TEST-4 ______________ , 3 NUMBERS"
	./$(NAME) 1 5 3
	@echo
	
	

.PHONY: all clean fclean re remsg test
