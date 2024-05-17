/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfreire <alfreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 17:04:21 by alfreire          #+#    #+#             */
/*   Updated: 2024/05/17 20:12:05 by alfreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	movement(int keycode, t_map *data)
{
	if (keycode == ESC)
		finish(data);
	else if (keycode == W)
		data->next = (t_point){data->ref.x, data->ref.y - 1};
	else if (keycode == A)
		data->next = (t_point){data->ref.x - 1, data->ref.y};
	else if (keycode == S)
		data->next = (t_point){data->ref.x, data->ref.y + 1};
	else if (keycode == D)
		data->next = (t_point){data->ref.x + 1, data->ref.y};
	return (keycode);
}

void	start_display(t_map	*data)
{
	data->disp.mlx = mlx_init();
	if (!data->disp.mlx)
		fail_message(data, "mlx pointer failed");
	data->disp.win = mlx_new_window(data->disp.mlx, PIX * data->colum, \
	PIX * data->lines, "so_long");
	if (!data->disp.win)
		fail_message(data, "Window pointer failed");
}

void	launch_sprites(t_map *data)
{
	data->sprt = malloc(7 * sizeof(t_sprite));
	if (!data->sprt)
		fail_message(data, "Image allocation error.\n");
	data->sprt[F1].img = mlx_xpm_file_to_image(data->disp.mlx, F,
			&(data->sprt[F1].width), &(data->sprt[F1].height));
	data->sprt[W1].img = mlx_xpm_file_to_image(data->disp.mlx, Wa,
			&(data->sprt[W1].width), &(data->sprt[W1].height));
	data->sprt[P1].img = mlx_xpm_file_to_image(data->disp.mlx, P,
			&(data->sprt[P1].width), &(data->sprt[P1].height));
	data->sprt[C1].img = mlx_xpm_file_to_image(data->disp.mlx, C,
			&(data->sprt[C1].width), &(data->sprt[C1].height));
	data->sprt[E1].img = mlx_xpm_file_to_image(data->disp.mlx, E,
			&(data->sprt[E1].width), &(data->sprt[E1].height));
	data->sprt[E2].img = mlx_xpm_file_to_image(data->disp.mlx, EO,
			&(data->sprt[E2].width), &(data->sprt[E2].height));
	data->sprt[E3].img = mlx_xpm_file_to_image(data->disp.mlx, EO,
			&(data->sprt[E3].width), &(data->sprt[E3].height));
}

void	start_game(char *filename)
{
	t_map	data;

	ft_bzero(&data, sizeof(t_map));
	read_map(filename, &data);
	check_map(&data);
	start_display(&data);
	launch_sprites(&data);
	create_map(&data);
	mlx_hook(data.disp.win, 2, (1L << 0), movement, &data);
	mlx_hook(data.disp.win, 17, 0, finish, &data);
	mlx_loop_hook(data.disp.mlx, &create_game, &data);
	mlx_loop(data.disp.mlx);
}