/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfreire <alfreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 15:22:09 by alfreire          #+#    #+#             */
/*   Updated: 2023/10/19 18:52:06 by alfreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stddef.h>
//#include <stdio.h>

char	*ft_strrchr(const char *str, int c)
{
	int		i;
	char	*lastc;

	i = 0;
	lastc = NULL;
	while (str[i] != '\0')
	{
		if ((unsigned char)str[i] == (unsigned char)c)
			lastc = (char *)&str[i];
		i++;
	}
	if ((unsigned char)str[i] == (unsigned char)c)
		lastc = (char *)&str[i];
	return (lastc);
}
