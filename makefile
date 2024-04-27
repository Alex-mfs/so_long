CC = gcc
CFLAGS = -Wall -Wextra -Werror -O3 -fPIE -I/usr/include -Iminilibx-linux
LDFLAGS = -L./minilibx-linux -lmlx -L/usr/lib -lXext -lX11 -lm -lz
SRC_PATH = ./src/
SRCS = $(SRC_PATH)main.c $(SRC_PATH)check_maps.c $(SRC_PATH)start.c
OBJ = $(SRCS:.c=.o)
NAME = so_long
LIBFT = ./libft/libft.a
LIBFT_INC = ./libft/libft.h

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(OBJ) $(LIBFT) $(LDFLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	$(MAKE) -C ./libft

clean:
	rm -f $(OBJ)
	$(MAKE) -C ./libft clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C ./libft fclean

re: fclean all

.PHONY: all clean re fclean
.SILENT: