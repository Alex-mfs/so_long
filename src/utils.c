/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfreire <alfreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 14:57:43 by alfreire          #+#    #+#             */
/*   Updated: 2024/05/20 18:19:41 by alfreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_flood_fill(t_map *map, t_point ref, char **dupmap)
{
	if (ref.x < 0 || ref.y < 0 \
		|| ref.x > (int)map->colum - 1 || ref.y > (int)map->lines - 1 \
		|| dupmap[ref.y][ref.x] == 'V' || dupmap[ref.y][ref.x] == '1')
		return ;
	else if (dupmap[ref.y][ref.x] == 'C')
		map->vp_collect++;
	else if (dupmap[ref.y][ref.x] == 'E')
	{
		map->vp_exit++;
		map->exit_pos = ref;
	}
	dupmap[ref.y][ref.x] = 'V';
	ft_flood_fill(map, (t_point){ref.x + 1, ref.y}, dupmap);
	ft_flood_fill(map, (t_point){ref.x - 1, ref.y}, dupmap);
	ft_flood_fill(map, (t_point){ref.x, ref.y + 1}, dupmap);
	ft_flood_fill(map, (t_point){ref.x, ref.y - 1}, dupmap);
}

void	free_mapmatrix(char **dupmap)
{
	int		i;

	i = 0;
	if (!dupmap)
		return ;
	while (dupmap[i])
	{
		free(dupmap[i]);
		i++;
	}
	free(dupmap);
}

int	ft_strchr_index(const char *s, int c)
{
	int		i;

	i = 0;
	if (!s)
		return (-1);
	while (s[i])
	{
		if (s[i] == (char)c)
			return (i);
		i++;
	}
	return (-1);
}

void	fail_message(t_map *data, char *message)
{
	ft_destroy_data(data);
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(message, 2);
	exit(EXIT_FAILURE);
}

void	player_on_exit(t_map *data, t_point pos)
{
	t_sprite	sprite;

	sprite = data->sprt[E3];
	mlx_put_image_to_window(data->disp.mlx, data->disp.win, sprite.img, \
		(pos.x * PIX), (pos.y * PIX));
}
