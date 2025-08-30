# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aykrifa <aykrifa@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/14 20:52:04 by aykrifa           #+#    #+#              #
#    Updated: 2025/08/27 11:58:57 by aykrifa          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= RelevantName
CC			= c++
CFLAGS		= -Wall -Wextra -Werror -std=c++98

INCLUDES	= header 
SRC_PATH	= srcs
OBJ_PATH	= objs

SRC_DIRS	= 
SRC_DIRS_PATHS = $(addprefix $(SRC_PATH)/,$(SRC_DIRS))

SOURCES		= main.cpp \

SRCS		= $(addprefix $(SRC_PATH)/,$(SOURCES))
OBJS		= $(addprefix $(OBJ_PATH)/,$(SOURCES:.cpp=.o))
DEPS		= $(OBJS:.o=.d)

all: $(OBJ_PATH) $(NAME) 

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

-include $(DEPS)

clean:
	rm -rf $(OBJ_PATH)

fclean: clean
	rm -f $(NAME)

re: fclean all

$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)
	$(foreach dir, $(SRC_DIRS), mkdir -p $(OBJ_PATH)/$(dir);)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.cpp
	$(CC) $(CFLAGS) -MMD -MP -c $< -o $@ -I$(INCLUDES)

bear:
	bear -- make re

.PHONY: all fsanitize clean fclean re
