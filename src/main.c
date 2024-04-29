/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfreire <alfreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 17:04:06 by alfreire          #+#    #+#             */
/*   Updated: 2024/04/29 16:24:33 by alfreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// if (all_collected && exit_count == 1)
// 	return (map_valid);
// if (on_wall)
// 	return (map_invalid);
// if (on_collectable)
// 	collectables++;
// if (on_exit)
// 	exits++;
// replace_current_position_with_wall;
// if (one_of_the_four_adjacent_directions_is_possible)
// 	return map_valid;
// return map_valid;

bool	valid_filename(char *filename)
{
	size_t	len;

	len = ft_strlen(filename);
	if (len < 4)
		return (false);
	if (ft_strnstr(filename + (len - 4), ".ber", 4) != NULL)
		return (true);
	else
		return (false);
}

int	main(int ac, char **av)
{
	if (ac != 2)
		return (EXIT_FAILURE);
	if (!valid_filename(av[1]))
		return (EXIT_FAILURE);
	start_game(av[1]);
}
