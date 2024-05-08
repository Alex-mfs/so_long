/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfreire <alfreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 17:34:00 by alfreire          #+#    #+#             */
/*   Updated: 2024/05/08 16:28:01 by alfreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	count;

	count = 0;
	if (!str || !*str)
		return (0);
	while (str[count] != '\0')
		count++;
	return (count);
}

/* int main(void)
{
		char    *p = "porto";
		printf("%d\n", ft_strlen(p));
} */