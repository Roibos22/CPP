# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/16 19:21:25 by lgrimmei          #+#    #+#              #
#    Updated: 2024/03/07 01:59:22 by lgrimmei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# COLORS FOR PRINTING
GREEN = \033[0;32m
RESET = \033[0m

# DIRECTORIES
OBJ_DIR = obj

# EXECUTABLE NAME
NAME = iter

# SOURCE FILES
SRCS =	main.cpp\

# OBJECT FILES
OBJS = $(SRCS:.cpp=.o)

# COMPILER
CC = c++

# COMPILATION FLAGS
CFLAGS = -Wall -Wextra -Werror -std=c++98

# COMMANDS
RM = rm -f
MKDIR = mkdir -p

# RULES
$(OBJ_DIR)/%.o: %.cpp
	@$(MKDIR) $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

all : $(NAME)

print-NAME:
	@echo $(NAME)

$(NAME) : $(addprefix $(OBJ_DIR)/, $(OBJS))
	@$(CC) $(CFLAGS) $^ -o $(NAME)
	@echo "$(GREEN)./$(NAME) is ready!$(RESET)"

fclean : clean
	@$(RM) $(NAME)

clean :
	@$(RM) -r $(OBJ_DIR)

re : fclean all

.PHONY : all clean fclean re