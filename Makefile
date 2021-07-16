# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aalcara- <aalcara-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/16 09:44:16 by aalcara-          #+#    #+#              #
#    Updated: 2021/07/16 13:18:25 by aalcara-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
LIBFT = libft.a

SRC_DIR = ./src/
OBJ_DIR = ./obj/
INC_DIR = ./inc/
LIBFT_DIR = ./libft/

CC = clang
CFLAGS = -Wall -Werror -Wextra

SRC = $(shell find $(SRC_DIR) -name *.c)
OBJ = $(subst $(SRC_DIR),$(OBJ_DIR),$(SRC:.c=.o))

all: $(NAME)

$(NAME): $(OBJ)
	@make --no-print-directory -C $(LIBFT_DIR)
	@$(CC) $(CFLAGS) $(OBJ) -I $(INC_DIR) -o $(NAME) -L $(LIBFT_DIR) -lft
	@echo "** $(NAME): Created! **"
	@echo

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)
	@make --no-print-directory -C $(LIBFT_DIR) clean
	@echo "!! .o files deleted !!"
	@echo

fclean: clean
	@rm -f $(NAME)
	@make --no-print-directory -C $(LIBFT_DIR) fclean
	@echo "!! [$(NAME)] deleted !!"
	@echo

re: fclean all

.PHONY: all clean fclean re



