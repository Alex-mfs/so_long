OS = $(shell uname)

MLX_DIR = minilibx-linux
MLX_LIB = -L./$(MLX_DIR) -lmlx -L/usr/lib -lXext -lX11 -lm -lz
CFLAGS = -Wall -Wextra -Werror -O3 -fPIE -I/usr/include -I$(MLX_DIR)

ifeq ($(OS), Darwin)
	MLX_DIR = minilibx_opengl
	MLX_LIB = -L./$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
	CFLAGS = -Wall -Wextra -Werror -O3 -fPIE -I/usr/include -I$(MLX_DIR)
endif
CC = gcc
LDFLAGS = $(MLX_LIB)
SRC_PATH = ./src/
SRCS = $(SRC_PATH)main.c $(SRC_PATH)read_map.c $(SRC_PATH)check_maps.c $(SRC_PATH)start.c
OBJ = $(SRCS:.c=.o)
NAME = so_long
LIBFT = ./libft/libft.a
LIBFT_INC = ./libft/libft.h

all: minilibx $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(OBJ) $(LIBFT) $(LDFLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	$(MAKE) -C ./libft

minilibx:
	$(MAKE) -C ./$(MLX_DIR)

clean:
	rm -f $(OBJ)
	$(MAKE) -C ./libft clean
	$(MAKE) -C ./$(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C ./libft fclean

re: fclean all

.PHONY: all clean re fclean minilibx
.SILENT: