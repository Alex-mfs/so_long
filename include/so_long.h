#ifndef SO_LONG_H
#define SO_LONG_H

#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "../libft/libft.h"

# ifdef __APPLE__
# include <Carbon/Carbon.h>
# elif defined(__linux__)
# include <X11/keysym.h>
# include <X11/X.h>

# endif

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_comp
{
	int	colec;
	int	exi;
}	t_comp;

typedef struct s_map
{
	char		**map;
	size_t		colum;
	size_t		lines;
	int			colect;
	int			player;
	int			exit;
	int			vp_exit;
	int			vp_colect;
	t_point		ref;
	t_comp		comp;
}	t_map;


typedef struct s_player
{
	/* data */
}	t_player;

// READ MAP //
char	read_map(const char *filename, t_map *data);

// CHECK MAPS //
void	check_map(t_map *data);
bool	rectangular_map(t_map *map);
bool	correct_characters(t_map *data);
bool	surrounded_map(t_map *data);
bool	valid_path(t_map *data);

// UTILS //
bool	ft_flood_fill(t_map *map, t_point ref, char **dupmap);
void	free_dupmap(char **dupmap);
int		ft_strchr_index(const char *s, int c);

// START //
void	start_game(char *filename);

#endif // SO_LONG_H
