/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfreire <alfreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 17:05:28 by alfreire          #+#    #+#             */
/*   Updated: 2023/10/19 18:39:05 by alfreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*concate;
	int		i;
	int		j;

	i = 0;
	j = 0;
	concate = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (concate == NULL)
		return (NULL);
	if (!s1 || !s2)
		return (NULL);
	while (s1[i])
	{
		concate[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		concate[i + j] = s2[j];
		j++;
	}
	concate[i + j] = '\0';
	return (concate);
}
