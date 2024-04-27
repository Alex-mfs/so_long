/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfreire <alfreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 12:40:32 by alfreire          #+#    #+#             */
/*   Updated: 2023/10/23 14:14:43 by alfreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_allocate(char **matstr, char const *s, char sep)
{
	char const	*word_end;
	char		**current_str;

	word_end = s;
	current_str = matstr;
	while (*word_end)
	{
		while (*s == sep)
			s++;
		word_end = s;
		while (*word_end && *word_end != sep)
			word_end++;
		if (*word_end == sep || word_end > s)
		{
			*current_str = ft_substr(s, 0, word_end - s);
			s = word_end;
			current_str++;
		}
	}
	*current_str = NULL;
}

static int	ft_count_words(char const *s, char sep)
{
	int	word_count;

	word_count = 0;
	while (*s)
	{
		while (*s == sep)
			s++;
		if (*s)
			word_count++;
		while (*s && *s != sep)
			s++;
	}
	return (word_count);
}

char	**ft_split(char const *s, char c)
{
	char	**matstr;
	int		num_words;

	if (!s)
		return (NULL);
	num_words = ft_count_words(s, c);
	matstr = malloc(sizeof(char *) * (num_words + 1));
	if (!matstr)
		return (NULL);
	ft_allocate(matstr, s, c);
	return (matstr);
}
