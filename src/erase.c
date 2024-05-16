/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erase.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfreire <alfreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 15:56:25 by alfreire          #+#    #+#             */
/*   Updated: 2024/05/16 17:48:27 by alfreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	sprite_destroy(t_map *data)
{
	int	i;

	i = 0;
	while(i < 5)
	{
		mlx_destroy_image(data->disp.mlx, data->sprt[i++].img);
		free(data->sprt);
	}
}

void	ft_destroy_data(t_map *data)
{
	if (!data)
		return ;
	if (data->sprt)
		sprite_destroy(data);
	if (data->disp.img_ptr)
		mlx_destroy_image(data->disp.mlx, data->disp.img_ptr);
	if (data->disp.win)
		mlx_destroy_window(data->disp.mlx, data->disp.win);
	if (data->disp.mlx)
		mlx_destroy_display(data->disp.mlx);
	if (data->map)
		free_mapmatrix(data->map);
	free(data->disp.mlx);
}

int	finish(t_map *data)
{
	ft_destroy_data(data);
	exit(0);
}