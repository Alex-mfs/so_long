/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfreire <alfreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:50:16 by alfreire          #+#    #+#             */
/*   Updated: 2023/10/19 18:55:07 by alfreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (big[i] != '\0' && i < len)
	{
		j = 0;
		while ((big[i + j] == little[j]) && big[i + j] != '\0' && i + j < len)
		{
			if (little[j + 1] == '\0')
				return ((char *)&big[i]);
			j++;
		}
		i++;
	}
	return (0);
}

// int	main()
// {
// 	const char *big = "acdefabcgh";
// 	const char *little = "abc";
// 	size_t len = 2; // Comprimento de big
// 	char *result = ft_strnstr(big, little, len);
// 	if (result != NULL)
// 	{
// 		printf("Substring encontrada: %s\n", result);
// 	}
// 	else
// 	{
// 		printf("Substring não encontrada.\n");
// 	}
// 	return (0);
// }