# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: leon <leon@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/07 21:45:45 by lgrimmei          #+#    #+#              #
#    Updated: 2024/05/05 18:53:31 by leon             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# COLORS FOR PRINTING
GREEN = \033[0;32m
RESET = \033[0m

# DIRECTORIES
OBJ_DIR = obj
SRC_DIR = src

# EXECUTABLE NAME
NAME = PmergeMe

# SOURCE FILES
SRCS =	main.cpp \
		PmergeMe.cpp

# OBJECT FILES
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.cpp=.o))

# COMPILER
CC = c++

# COMPILATION FLAGS
CFLAGS = -Wall -Wextra -Werror -std=c++98

# COMMANDS
RM = rm -f
MKDIR = mkdir -p

# DIRECTORIES
INCL_DIR = incl

# RULES
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@$(MKDIR) $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I $(INCL_DIR) -c $< -o $@

all : $(NAME)

print-NAME:
	@echo $(NAME)

$(NAME) : $(OBJS)
	@$(CC) $(CFLAGS) -I $(INCL_DIR) $^ -o $(NAME)
	@echo "$(GREEN)./$(NAME) is ready!$(RESET)"

fclean : clean
	@$(RM) $(NAME)

clean :
	@$(RM) -r $(OBJ_DIR)

re : fclean all

.PHONY : all clean fclean re