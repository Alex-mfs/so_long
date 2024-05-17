/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfreire <alfreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 20:00:04 by alfreire          #+#    #+#             */
/*   Updated: 2024/05/17 20:18:06 by alfreire         ###   ########.fr       */
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

void	player_movement(t_map *data)
{
	char	prev;
	t_point	p;
	
	p = data->next;
	prev = '0';
	data->map[data->ref.y][data->ref.x] = prev;
	if (data->map[p.y][p.x] != 'C')
		prev = data->map[data->next.y][data->next.x];
	else
		prev = '0';
	data->map[data->next.y][data->next.x] = 'P';
	put_sprites(data, (t_point){data->ref.x, data->ref.y});
	put_sprites(data, (t_point){data->next.x, data->next.y});
	data->ref = data->next;
}

bool	can_move(t_map	*data)
{
	t_point	p;

	p = data->next;
	if (p.y == data->ref.y && p.x == data->ref.x)
		return (false);
	else if (data->map[p.y][p.x] == '1')
		return (false);
	return (true);
}

int		create_game(t_map *data)
{
	if (!can_move(data))
		return (0);
	ft_putstr_fd("Number of movements: ", 1);
	data->num_moves++;
	ft_putnbr_fd(data->num_moves, 1);
	ft_putchar_fd('\n', 1);
	if (data->map[data->next.y][data->next.x] == 'C')
		data->collected++;
	else if (data->map[data->next.y][data->next.x] == 'E')
	{
		if (data->collected == data->collect)
			finish(data);
	}
	player_movement(data);
	return (0);
}