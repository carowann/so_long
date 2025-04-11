# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cwannhed <cwannhed@student.42firenze.it>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/19 14:25:47 by cwannhed          #+#    #+#              #
#    Updated: 2025/04/07 18:21:39 by cwannhed         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

MLX_DIR = minilibx-linux
MLX_LIBS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

SRC_DIR = .
INC_DIR = .
OBJ_DIR = objs


SRCS =	main.c					\
		args_parser.c			\
		map_parser.c			\
		map_validation.c		\
		map_checks.c			\
		map_utils.c				\
		map_to_matrix.c 		\
		error_handler.c			\
		map_path_validation.c	\
		map_render.c			\
		mlx_events.c			\
		mlx_textures.c			\
		mlx_utils.c				\
		mlx_window.c			\
		player_movements.c


OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(LIBFT):
	@echo "Compiling libft..."
	@$(MAKE) -C $(LIBFT_DIR) --no-print-directory
	@echo "Libft compiled successfully!"
	
$(NAME): $(OBJ_DIR) $(OBJS) $(LIBFT)
	@echo "Linking $(NAME)..."
	@$(CC) $(CFLAGS) $(OBJS) -I$(INC_DIR) -L$(LIBFT_DIR) -lft $(MLX_LIBS) -o $(NAME)
	@echo "$(NAME) created successfully!"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@echo "Compiling $<..."
	@$(CC) $(CFLAGS) -c -I$(INC_DIR) $< -o $@

clean:
	@echo "Cleaning object files..."
	@rm -rf $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean --no-print-directory
	@echo "Object files cleaned!"

fclean: clean
	@echo "Removing library $(NAME)..."
	@$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean --no-print-directory
	@echo "Library $(NAME) removed!"

re: fclean all

.PHONY: all clean fclean re