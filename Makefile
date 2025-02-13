# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/07 18:35:52 by lsilva-x          #+#    #+#              #
#    Updated: 2025/02/12 20:44:44 by lsilva-x         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC 			= cc
NAME		= push_swap
CFLAG		= -Wall -Wextra -Werror -Wunreachable-code -Ofast -g

LIBFT_DIR	= libft
LIBFT_LIB	= $(LIBFT_DIR)/libft.a

SRC			=	main.c \
				common_functions.c \
				input_checker.c \
				struct_functions.c \
				utils_functions.c \
				verify_functions.c \
				operations.c \
				sort_stack.c



OBJ_DIR		= ./build
OBJ			= $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT_LIB)
	$(CC) $(CFLAG) -o $(NAME) $(OBJ) $(LIBFT_LIB)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAG) -c $< -o $@

$(LIBFT_LIB):
	make -C $(LIBFT_DIR)

clean:
	rm -f $(OBJ)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re
