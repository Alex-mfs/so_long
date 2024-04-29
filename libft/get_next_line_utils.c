/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfreire <alfreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:32:22 by alfreire          #+#    #+#             */
/*   Updated: 2024/04/29 18:46:24 by alfreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strclen(const char *str, int c)
{
	size_t	count;

	count = 0;
	if (!str)
		return (0);
	while (str[count] && str[count] != c)
		count++;
	return (count);
}

char	*ft_strjoingnl(char *s1, char *s2)
{
	char	*concate;
	int		i;
	int		total_size;

	i = 0;
	total_size = 0;
	if (s1)
		total_size = ft_strclen(s1, '\0');
	total_size += ft_strclen(s2, '\0') + 1;
	concate = malloc(total_size);
	if (!concate)
		return (NULL);
	if (s1)
		while (s1[i])
			*(concate++) = s1[i++];
	concate -= ft_strclen(s1, '\0');
	while (*s2)
		concate[i++] = *(s2++);
	concate[i] = '\0';
	if (s1)
		free(s1);
	return (concate);
}

char	*ft_strchr_gnl(const char *str, int c)
{
	int	i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i])
	{
		if (str[i] == c)
			return ((char *)str + i);
		i++;
	}
	return (NULL);
}

char	*ft_strldup(const char *src, size_t len)
{
	char	*dup;
	size_t	i;

	i = 0;
	dup = malloc(len + 1);
	if (!dup)
		return (NULL);
	while (src[i] && i < len)
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
