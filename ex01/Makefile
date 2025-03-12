# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: miwasa <miwasa@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/12 15:47:49 by miwasa            #+#    #+#              #
#    Updated: 2025/03/12 15:49:01 by miwasa           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= Span

CXX			:= c++
CXXFLAGS	:= -Wall -Wextra -Werror
CXXFLAGS	+= -std=c++98

SRCS		:= main.cpp \
				Span.cpp

OBJS_DIR	:= obj
OBJS		:= $(addprefix $(OBJS_DIR)/, $(SRCS:.cpp=.o))

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(OBJS_DIR)/%.o: %.cpp
	mkdir -p $(OBJS_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) -r $(OBJS_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all
