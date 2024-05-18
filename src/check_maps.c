/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_maps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfreire <alfreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 17:03:53 by alfreire          #+#    #+#             */
/*   Updated: 2024/05/18 18:05:04 by alfreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// int		check_walls(t_map	map)
// {
// 	if ();
// }
// void	set_struct(t_map data)
// {
// 	data.collect = 0;
// 	data.colum = 0;
// 	data.exit = 0;
// 	data.lines = 0;
// 	data.map = NULL;
// }


// i itera sobre as linhas do mapa, comeca na 0 e assim por diante
bool	rectangular_map(t_map *data)
{
	size_t		i;

	if (!data || !data->map || !data->map[0])
		return (false);
	data->colum = ft_strlen(data->map[0]);
	i = 0;
	while (data->map[i] != NULL)
	{
		if (ft_strlen(data->map[i]) != data->colum)
			return (false);
		data->lines++;
		i++;
	}
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
		if (i == 0 || i == data->lines - 1)
		{
			j = 0;
			while(data->map[i][j])
			{
				if (data->map[i][j] != '1')
					return (false);
				j++;
			}
		}
		else
			if (data->map[i][0] != '1' || data->map[i][data->colum - 1] != '1')
				return (false);
		i++;
	}
	return (true);
}

bool	correct_characters(t_map *data)
{
	int		i;
	int		j;

	i = -1;
	while (data->map[++i])
	{
		j = -1;
		while(data->map[i][++j] && data->map[i][j]!= '\n')
		{
			if (data->map[i][j] == 'P')
			{
				data->ref.x = j;
				data->ref.y = i;
				data->player++;
			}
			else if (data->map[i][j] == 'E')
				data->exit++;
			else if (data->map[i][j] == 'C')
				data->collect++;
			else if (ft_strchr_index("CEP10", data->map[i][j]) == -1)
				return (false);
		}
	}
	return (data->collect >= 1 && data->player == 1
			&& data->exit == 1);
}

bool	valid_path(t_map *data)
{
	char	**dupmap;
	size_t		i;

	dupmap = malloc(sizeof(char *) * (data->lines + 1));
	if (!dupmap)
		return (false);
	i = 0;
	while (i < data->lines)
	{
		dupmap[i] = ft_strdup(data->map[i]);
		if (!dupmap[i])
		{
			free_mapmatrix(dupmap);
			return (false);
		}
		i++;
	}
	dupmap[i] = NULL;
	ft_flood_fill(data, data->ref, dupmap);
    i = 0;
	while (dupmap[i])
	{
	    printf("%s\n", dupmap[i]);
		i++;
	}
	free_mapmatrix(dupmap);
	return (data->vp_collect == data->collect && data->vp_exit == data->exit);
}

void	check_map(t_map *data)
{
	if (!rectangular_map(data))
		ft_putstr_fd("Error\nMap is not rectangular", 2);
	if (!surrounded_map(data))
		ft_putstr_fd("Error\nMap is not fully surrounded by walls", 2);
	if (!correct_characters(data))
		ft_putstr_fd("Error\nMap do not have all the neccessary characters", 2);
	if (!valid_path(data))
		ft_putstr_fd("Error\nMap path is not valid", 2);
	//free_mapmatrix(data->map);
}
