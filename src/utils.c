/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfreire <alfreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 14:57:43 by alfreire          #+#    #+#             */
/*   Updated: 2024/05/08 19:57:06 by alfreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void ft_flood_fill(t_map *map, t_point ref, char **dupmap)
{

	// ft_putstr_fd("a\n", 1);
	// printf("%d\n", dupmap[ref.x][ref.y]);
	// printf("x: %d, y: %d\n",(int)map->colum , (int)map->lines);

	if (ref.x < 0 || ref.y < 0 ||
		ref.x > (int)map->colum - 1 || ref.y > (int)map->lines - 1 ||
		dupmap[ref.y][ref.x] == 'V' || dupmap[ref.y][ref.x] == 1)
	{
		ft_putstr_fd("falsa\n", 1);
		return false;
	}
	else if (dupmap[ref.y][ref.x] == 'C')
		map->vp_colect++;
	// ft_putstr_fd("c\n", 1);
	else if (dupmap[ref.y][ref.x] == 'E')
		map->vp_exit++;
	dupmap[ref.y][ref.x] = 'V';
	ft_flood_fill(map, (t_point){ref.x - 1, ref.y}, dupmap);
	ft_flood_fill(map, (t_point){ref.x + 1, ref.y}, dupmap);
	ft_flood_fill(map, (t_point){ref.x, ref.y + 1}, dupmap);
	ft_flood_fill(map, (t_point){ref.x, ref.y - 1}, dupmap);
}

void	free_dupmap(char **dupmap)
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

int		ft_strchr_index(const char *s, int c)
{
    int	i;

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