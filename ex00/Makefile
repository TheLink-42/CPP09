# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbaeza-c <jbaeza-c@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/08 03:13:48 by jimmy             #+#    #+#              #
#    Updated: 2025/03/13 13:35:32 by jbaeza-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Colors
CYAN = \033[0;36m
BLACK = \033[0;30m
RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
MAGENTA = \033[0;35m
WHITE = \033[0;37m

RESET = \033[0m


# Target
NAME = easyFind



# Directories
INC_DIR = inc
SRC_DIR = src/
OBJ_DIR = obj/

# Source files
SRC = 	$(SRC_DIR)main.cpp

# Object files
OBJ = $(SRC:$(SRC_DIR)%.cpp=$(OBJ_DIR)%.o)



# Compiler
CPP = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -I $(INC_DIR)
RM = rm -rf



# Rules
all: $(NAME)

clean:
	@$(RM) $(OBJ_DIR)
	@echo "$(MAGENTA)object files $(RED)removed$(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(MAGENTA)$(NAME) $(RED)removed$(RESET)"

re: fclean all


$(NAME): $(OBJ)
	@$(CPP) $(CPPFLAGS) $(OBJ) -o $(NAME)
	@echo "$(MAGENTA)$(NAME) $(GREEN)compiled$(RESET)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	@mkdir -p $(@D)
	@$(CPP) $(CPPFLAGS) -c $< -o $@
	