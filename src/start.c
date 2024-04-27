/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfreire <alfreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 17:04:21 by alfreire          #+#    #+#             */
/*   Updated: 2024/04/27 18:07:18 by alfreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	start_game(char *filename)
{
	t_map	data;

	ft_bzero(&data, sizeof(t_map));
	read_map(filename, &data);
	check_map(&data);
}