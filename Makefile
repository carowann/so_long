# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cwannhed <cwannhed@student.42firenze.it>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/19 14:25:47 by cwannhed          #+#    #+#              #
#    Updated: 2025/08/19 11:51:57 by cwannhed         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

MLX_DIR = minilibx-linux
MLX_LIBS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm
MLX_URL = https://github.com/42Paris/minilibx-linux.git

SRC_DIR = .
INC_DIR = .
OBJ_DIR = objs


SRCS =	main.c					\
		args_parser.c			\
		map_parser.c			\
		map_validation.c		\
		map_utils.c			\
		map_to_matrix.c 		\
		error_handler.c			\
		map_path_validation.c		\
		map_render.c			\
		mlx_events.c			\
		mlx_textures.c			\
		mlx_window.c			\
		player_movements.c


OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)

all: mlx_setup $(NAME)

mlx_setup:
	@if [ ! -d "$(MLX_DIR)" ]; then \
		echo "MiniLibX not found. Downloading..."; \
		git clone $(MLX_URL) $(MLX_DIR); \
		echo "MiniLibX downloaded successfully!"; \
	fi
	@if [ ! -f "$(MLX_DIR)/libmlx.a" ]; then \
		echo "Building MiniLibX..."; \
		$(MAKE) -C $(MLX_DIR) --no-print-directory; \
	fi

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR) --no-print-directory

$(NAME): $(OBJ_DIR) $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS) -I$(INC_DIR) -L$(LIBFT_DIR) -lft $(MLX_LIBS) -o $(NAME)
	@echo "$(NAME) created successfully!"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c -I$(INC_DIR) $< -o $@

clean:
	@rm -rf $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean --no-print-directory
	@echo "So_long object files cleaned!"

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean --no-print-directory
	@echo "$(NAME) removed!"

re: fclean all

.PHONY: all clean fclean re mlx_setup