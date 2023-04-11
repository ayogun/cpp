# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/07 14:30:54 by yogun             #+#    #+#              #
#    Updated: 2023/04/11 23:38:06 by yogun            ###   ########.fr        #
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
NAME = BureaucratEXE

# Set the source files to compile
SRC = main.cpp Bureaucrat.cpp

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

.PHONY: all clean fclean re remsg
