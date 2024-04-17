#include "../minilibx-linux/mlx.h"
#include <X11/keysym.h>
#include <X11/X.h>
#include <stdlib.h>
#include <stdio.h>

// if (all_collected && exit_count == 1)
// 	return (map_valid);
// if (on_wall)
// 	return (map_invalid);
// if (on_collectable)
// 	collectables++;
// if (on_exit)
// 	exits++;
// replace_current_position_with_wall;
// if (one_of_the_four_adjacent_directions_is_possible)
// 	return map_valid;
// return map_valid;

// typedef struct s_data
// {
// 	void		*mlx_ptr;
// 	void		*win_ptr;
// 	void		*textures[5];
// 	t_map		*map;
// }	t_data;

int	main(void)
{
	void	*mlx;
	void	*win;
	char	*relative_path = "./assets/texture.xpm";
	int		img_width;
	int		img_height;

	mlx = mlx_init();
	if (!mlx)
		return (1);
	win = mlx_new_window(mlx, 600, 400, "window");
	if (!win)
		{
			mlx_destroy_display(mlx);
			free(mlx);
			return (1);
		}
	void	*img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
	if (!img)
	{
		printf("erro ao carregar imagem.\n");
		mlx_destroy_window(mlx, win);
		mlx_destroy_display(mlx);
		free(mlx);
		return (1);
	}
	mlx_put_image_to_window(mlx, win, img, 100, 100);
	mlx_loop(mlx);
}