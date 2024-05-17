OS = $(shell uname)

MLX_DIR = minilibx-linux
MLX_LIB = -L./$(MLX_DIR) -lmlx -L/usr/lib -lXext -lX11 -lm -lz
CFLAGS = -Wall -Wextra -Werror -g -O3 -fPIE -I/usr/include -I$(MLX_DIR)

ifeq ($(OS), Darwin)
	MLX_DIR = minilibx_opengl
	MLX_LIB = -L./$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
	CFLAGS = -Wall -Wextra -Werror -O3 -fPIE -I/usr/include -I$(MLX_DIR)
endif
CC = gcc
LDFLAGS = $(MLX_LIB) -L./libft -lft
SRC_PATH = ./src/
SRCS = $(SRC_PATH)main.c $(SRC_PATH)read_map.c $(SRC_PATH)utils.c $(SRC_PATH)check_maps.c $(SRC_PATH)start.c $(SRC_PATH)create.c $(SRC_PATH)erase.c
OBJ = $(SRCS:.c=.o)
NAME = so_long
LIBFT = ./libft/libft.a
LIBFT_INC = ./libft/libft.h

.SILENT:

all: minilibx $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(OBJ) $(LDFLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	$(MAKE) -C ./libft --silent

minilibx:
	$(MAKE) -C ./$(MLX_DIR) --silent > /dev/null

clean:
	rm -f $(OBJ)
	$(MAKE) -C ./libft clean > /dev/null
	$(MAKE) -C ./$(MLX_DIR) clean --silent > /dev/null

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C ./libft fclean --silent > /dev/null

re: fclean all

.PHONY: all clean re fclean minilibx