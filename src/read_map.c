/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfreire <alfreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 17:06:35 by alfreire          #+#    #+#             */
/*   Updated: 2024/04/29 19:03:54 by alfreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

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
	data->map = ft_split(tmp, '\n');
	printf("%s", tmp);
	free(line);
	return (0);
}
