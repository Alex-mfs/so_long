/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_maps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfreire <alfreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 17:03:53 by alfreire          #+#    #+#             */
/*   Updated: 2024/05/01 17:07:34 by alfreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// int		check_walls(t_map	map)
// {
// 	if ();
// }
// void	set_struct(t_map data)
// {
// 	data.colect = 0;
// 	data.colum = 0;
// 	data.exit = 0;
// 	data.lines = 0;
// 	data.map = NULL;
// }

bool	rectangular_map(t_map *map)
{
	char		**lines;
	size_t		i;

	lines = map->map;
	if (lines[0])
		map->colum = ft_strlen(lines[0]);
	i = 0;
	while (lines[i] != NULL)
	{
		if (ft_strlen(lines[i]) != map->colum)
			return (false);
		i++;
	}
	map->lines = i;
	while (lines[i++])
		free(lines[i]);
	free(lines);
	return (true);
}

bool	surrounded_map(t_map *data)
{
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;

	while (i < data->lines)
	{
		if (i == 0 || i == data->lines - 2)
		{
			j = 0;
			printf("\n%zu\n", data->lines);
			printf("\n%zu\n", data->colum);
			while(j < data->colum - 1)
			{
				if (data->map[i][j] != '1')
					return (false);
				j++;
			}
			ft_putstr_fd("\na\n", 1);
		}
		else
			if (data->map[i][0] != '1' || data->map[i][data->colum - 1] != '1')
				return (false);
		i++;
	}
	return (true);
}

void	check_map(t_map *data)
{
    int i = 0;
    while (data->map[i++])
        printf("%s\n", data->map[i]);
	if (!rectangular_map(data))
		ft_putstr_fd("Error\nMap is not rectangular", 2);
	if (!surrounded_map(data))
		ft_putstr_fd("Error\nMap is not fully surrounded by walls", 2);
}
