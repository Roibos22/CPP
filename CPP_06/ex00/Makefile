# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/16 19:21:25 by lgrimmei          #+#    #+#              #
#    Updated: 2024/04/29 13:23:55 by lgrimmei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# COLORS FOR PRINTING
GREEN = \033[0;32m
RESET = \033[0m

# DIRECTORIES
OBJ_DIR = obj
SRC_DIR = src

# EXECUTABLE NAME
NAME = convert

# SOURCE FILES
SRCS =	main.cpp\
		ScalarConverter.cpp

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