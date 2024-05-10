/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_maps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfreire <alfreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 17:03:53 by alfreire          #+#    #+#             */
/*   Updated: 2024/05/09 16:08:16 by alfreire         ###   ########.fr       */
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
	printf("AAAAAAAAAAAAAAAAAAAA%ld\n", data->lines);
	while (i < data->lines)
	{
		if (i == 0 || i == data->lines - 1)
		{
			j = 0;
			printf("\n%zu\n", data->lines);
			printf("\n%zu\n", data->colum);
			while(data->map[i][j])
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

bool	correct_characters(t_map *data)
{
	unsigned int		i;
	unsigned int		j;

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
				data->colect++;
			else if (ft_strchr_index("CEP10", data->map[i][j]) == -1)
				return (false);
		}
	}
	return (data->colect >= 1 && data->player == 1
			&& data->exit == 1);
}

bool	valid_path(t_map *data)
{
	char	**dupmap;
	size_t		i;

	dupmap = malloc(sizeof(char *) * (data->lines + 1));
	if (!dupmap)
	{
		ft_putstr_fd("eita", 2);
		return (false);
	}
	i = 0;
	while (i < data->lines)
	{
		dupmap[i] = ft_strdup(data->map[i]);
		if (!dupmap[i])
		{
			free_mapmatrix(dupmap);
			ft_putstr_fd("vish\n", 2);
			return (false);
		}
		i++;
	}
	dupmap[i] = NULL;
	ft_flood_fill(data, data->ref, dupmap);
	free_mapmatrix(dupmap);
	return (data->vp_colect == data->colect && data->vp_exit == data->exit);
}

void	check_map(t_map *data)
{
    int i = 0;
    while (data->map[i])
	{
	    printf("%s\n", data->map[i]);
		i++;
	}
	if (!rectangular_map(data))
		ft_putstr_fd("Error\nMap is not rectangular", 2);
	if (!surrounded_map(data))
		ft_putstr_fd("Error\nMap is not fully surrounded by walls", 2);
	if (!correct_characters(data))
		ft_putstr_fd("Error\nMap do not have all the neccessary characters", 2);
	if (!valid_path(data))
		ft_putstr_fd("Error\nMap path is not valid", 2);
	free_mapmatrix(data->map);
}
