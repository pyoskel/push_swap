# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pabartoc <pabartoc@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/24 19:15:28 by pabartoc          #+#    #+#              #
#    Updated: 2026/03/08 18:22:09 by pabartoc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SILENT :

NAME = push_swap

HEADER = push_swap.h

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

SOURCE =	push_swap.c \
			.c \

OBJECTS = $(SOURCE:.c=.o)

# Default rule
all: $(NAME)

# Create the static library
$(NAME): $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)
	echo "\033[1;32m ✅ [push_swap created]\033[0m"
	
# Rule for compiling .c \ files into .o files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean object files
clean:
	@rm -f $(OBJECTS)

# Clean everything (object files and library)
fclean: clean
	@rm -f $(NAME)

# Rebuild everything
re: fclean all

.PHONY: all clean fclean re