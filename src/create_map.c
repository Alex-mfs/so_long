/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfreire <alfreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 20:00:04 by alfreire          #+#    #+#             */
/*   Updated: 2024/05/16 14:14:57 by alfreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	put_sprites(t_map *data, t_point pos)
{
	t_sprite	sprite;

	if (data->map[pos.y][pos.x] == '0')
		sprite = data->sprt[F1];
	else if (data->map[pos.y][pos.x] == '1')
		sprite = data->sprt[W1];
	else if (data->map[pos.y][pos.x] == 'P')
		sprite = data->sprt[P1];
	else if (data->map[pos.y][pos.x] == 'C')
		sprite = data->sprt[C1];
	else if (data->map[pos.y][pos.x] == 'E')
		sprite = data->sprt[E1];
	else
		sprite = data->sprt[F1];
	mlx_put_image_to_window(data->disp.mlx, data->disp.win,\
		sprite.img, (pos.x * PIX), (pos.y * PIX));
}

void	create_map(t_map *data)
{
	unsigned int	i;
	unsigned int	j;

	printf("a");
	i = 0;
	while(data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			put_sprites(data, (t_point){j, i});
			j++;
		}
		i++;
	}
}