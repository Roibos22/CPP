# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/26 16:28:48 by lgrimmei          #+#    #+#              #
#    Updated: 2024/02/01 17:00:49 by lgrimmei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# COLORS FOR PRINTING
GREEN = \033[0;32m
RESET = \033[0m

# EXECUTABLE NAME
NAME		=	megaphone

# SOURCE FILES
SRCS		=	megaphone.cpp

# COMPILER
CC			=	c++

# COMPILATION FLAGS
CFLAGS		=	-Wall -Wextra -Werror -std=c++98

# COMMANDS
RM			=	rm -f

# OBJECT FILES
OBJS		=	$(SRCS:.cpp=.o)

# RULES
%.o: %.cpp
	@$(CC) $(CFLAGS) -c $< -o $@

all : $(NAME)

$(NAME)	: $(OBJS)
	@$(CC) $(CFLAGS) $^ -o $(NAME)
	@echo "$(GREEN)./$(NAME) is ready!$(RESET)"

fclean		: clean
	@$(RM) $(NAME)

clean		:
	@$(RM) $(OBJS)

re			:	fclean all

.PHONY		:	all clean fclean re
