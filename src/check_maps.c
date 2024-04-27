/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_maps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfreire <alfreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 17:03:53 by alfreire          #+#    #+#             */
/*   Updated: 2024/04/27 19:49:53 by alfreire         ###   ########.fr       */
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

bool	rectangular_map(char *map)
{
	char	**lines;
	int		num_columns;
	int		i;

	
}

void	check_map(t_map *data)
{
	if(!rectangular_map(data->map))
		perror("map not rectangular");                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              
}

char	read_map(const char *filename, t_map *data)
{
	int		fd;
	char	*tmp;
	char	*line;

	tmp = "";
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		perror ("error, file not found\n");
		exit (EXIT_FAILURE);
	}
	line = get_next_line(fd);
	while (line)
	{
		tmp = ft_strjoin(tmp, line);
		line = get_next_line(fd);
	}
	close (fd);
	data->map = tmp;
	printf("%s", tmp);
	free(line);
	return (0);
}