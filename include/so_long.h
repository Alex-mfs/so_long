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
#include <../minilibx_opengl/mlx.h>
# elif defined(__linux__)
# include <X11/keysym.h>
# include <X11/X.h>
# include <../minilibx-linux/mlx.h>
# endif

# define F "./assets/board.xpm"
# define Wa "./assets/wall.xpm"
# define P "./assets/player.xpm"
# define C "./assets/collect.xpm"
# define E "./assets/exit.xpm"

# define PIX	64


typedef enum e_index
{
	F1,
	W1,
	P1,
	C1,
	E1
}			t_index;

typedef	enum e_key
{
	ESC = 65307,
	W = 119,
	A = 97,
	S = 115,
	D = 100
}			t_key;

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_disp
{
	void	*mlx;
	void	*win;
	void	*img_ptr;
	char	*addr;
	int		bpp;
	int		endian;
	int		line_len;
	int		height;
	int		width;

}	t_disp;

typedef struct s_sprite
{
	void	*img;
	int		width;
	int		height;
}	t_sprite;

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
	t_point		next;
	t_disp		disp;
	t_sprite	*sprt;
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
void	ft_flood_fill(t_map *map, t_point ref, char **dupmap);
void	free_mapmatrix(char **dupmap);
int		ft_strchr_index(const char *s, int c);
void	fail_message(t_map *data, char *message);

// ERASE //
void	ft_destroy_data(t_map *data);

// CREATE_MAP //
void	create_map(t_map *data);

// START //
void	start_game(char *filename);

#endif // SO_LONG_H
