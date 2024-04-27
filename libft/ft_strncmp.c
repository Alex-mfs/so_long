/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfreire <alfreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 12:38:12 by alfreire          #+#    #+#             */
/*   Updated: 2023/10/05 14:48:49 by alfreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0')
		i++;
	if (i >= n)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
/*int	main()
{
	const char *str1 = "Hello, world!";
	const char *str2 = "Hello, world!";
	size_t n = 5;

	int	result_ft = ft_strncmp(str1, str2, n);
	int result_std = strncmp(str1, str2, n);

	if (result_ft == result_std)
	{
		printf("ft_strncmp e strncmp retornam o msm resultado: %d\n", result_ft);
	}
	else
		printf("ft_strncmp e strncmp retornam resultados diferentes.\n");
	return (0);
}*/
