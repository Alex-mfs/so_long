#ifndef SO_LONG_H
#define SO_LONG_H

#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>
#include <X11/keysym.h>
#include <X11/X.h>
#include <stdlib.h>
#include <fcntl.h>
#include "../libft/libft.h"

typedef struct s_map
{
	char	*map;
	int		colum;
	int		lines;
	int		colect;
	int		player;
	int		exit;
}	t_map;

typedef struct s_player
{
	/* data */
}	t_player;

char	read_map(const char *filename, t_map *data);
void	check_map(t_map *data);
bool	rectangular_map(char *map);

// START //
void	start_game(char *filename);

#endif // SO_LONG_H
