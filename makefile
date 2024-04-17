# CC = gcc
# CFLAGS = -Wall -Wextra -Werror
# SRC_PATH = ./src/
# SRCS = $(SRC_PATH)main.c
# OBJ = $(SRCS:.c=.o)
# NAME = so_long

# all: $(NAME)

# $(NAME): $(OBJ)
# 	$(CC) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Iminilibx-linux -lXext -lX11 -lm -lz -o $(NAME)


# %.o: %.c
# 	$(CC) -Wall -Wextra -Werror -I/usr/include -Iminilibx-linux -O3 -c $< -o $@

# clean:
# 	rm -f $(OBJ)

# fclean: clean
# 	rm -f $(NAME)

# re: fclean all

CC = gcc
CFLAGS = -Wall -Wextra -Werror -O3 -I/usr/include -Iminilibx-linux
LDFLAGS = -L/home/alfreire/CommonCore/so_long/minilibx-linux -lmlx -L/usr/lib -lXext -lX11 -lm -lz
SRC_PATH = ./src/
SRCS = $(SRC_PATH)main.c
OBJ = $(SRCS:.c=.o)
NAME = so_long

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(LDFLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
