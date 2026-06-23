# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pabartoc <pabartoc@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/24 19:15:28 by pabartoc          #+#    #+#              #
#    Updated: 2026/06/23 02:53:11 by pabartoc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror -I inc -I libft/inc

# Ordner-Struktur
SRC_DIR     = src
INC_DIR     = inc
LIBFT_DIR   = libft

# Die Library
LIBFT       = $(LIBFT_DIR)/libft.a

# Quelldateien und Objektdateien
SRCS        = $(SRC_DIR)/push_swap.c \
			  $(SRC_DIR)/stack_utils.c \
			  $(SRC_DIR)/utils.c \
			  $(SRC_DIR)/validation.c \
			  $(SRC_DIR)/index.c \
			  $(SRC_DIR)/swap.c \
			  $(SRC_DIR)/push.c \
			  $(SRC_DIR)/rotate.c \
			  $(SRC_DIR)/rev_rotate.c

OBJS        = $(SRCS:.c=.o)

# Default rule
all: $(NAME)

# Baut das eigentliche push_swap Programm
$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Baut die libft, indem es in den libft-Ordner geht und dort 'make' ausführt
$(LIBFT):
	@make -C $(LIBFT_DIR)

# Löscht die generierten .o Dateien (auch in der libft)
clean:
	@make -C $(LIBFT_DIR) clean
	rm -f $(OBJS)

# Löscht die .o Dateien UND die fertigen Programme/Libraries
fclean: clean
	@make -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

# Rebuild everything
re: fclean all

# Phony verhindert Konflikte, falls es Dateien gibt, die so heißen wie unsere Regeln
.PHONY: all clean fclean re