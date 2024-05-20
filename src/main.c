/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfreire <alfreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 17:04:06 by alfreire          #+#    #+#             */
/*   Updated: 2024/05/20 18:31:58 by alfreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

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
		fail_message(NULL, "Not a valid number of parameters.\n");
	if (!valid_filename(av[1]))
		fail_message(NULL, "Not a valid file name\n");
	start_game(av[1]);
}
