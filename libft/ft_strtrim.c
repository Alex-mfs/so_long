/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfreire <alfreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 17:05:12 by alfreire          #+#    #+#             */
/*   Updated: 2023/10/23 14:51:48 by alfreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimmed;
	size_t	end;
	size_t	start;

	if (!s1 || !set)
		return (NULL);
	if (ft_strlen(s1) == 0)
	{
		trimmed = malloc(sizeof(char) * 1);
		trimmed[0] = '\0';
		return (trimmed);
	}
	start = 0;
	end = ft_strlen(s1) - 1;
	while (ft_strchr(set, s1[start]) && s1[start])
		start++;
	while (ft_strchr(set, s1[end]) && end >= start)
		end--;
	trimmed = malloc(sizeof(char) * (end - start + 2));
	if (!trimmed)
		return (NULL);
	ft_strlcpy(trimmed, &s1[start], end - start + 2);
	return (trimmed);
}

/* int main(void)
{
    const char *original = "   xxx   xxx";
    const char *set = " x"; // Caracteres de preenchimento: espaço e tabulação

    char *trimmed = ft_strtrim(original, set);

    printf("String original: \"%s\"\n", original);
    printf("String após strtrim: \"%s\"\n", trimmed);

    free(trimmed); // Não esqueça de liberar a memória alocada
    return 0;
} */