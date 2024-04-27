/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfreire <alfreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 17:33:38 by alfreire          #+#    #+#             */
/*   Updated: 2023/10/20 13:59:29 by alfreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	tamanhodest;
	size_t	tamanhosrc;
	size_t	i;

	tamanhodest = 0;
	tamanhosrc = 0;
	if (!size)
	{
		return (ft_strlen(src) + size);
	}
	tamanhosrc = ft_strlen((char *)src);
	i = 0;
	while (dst[i] != '\0' && i < size)
		i++;
	tamanhodest = i;
	while (src[i - tamanhodest] && i < size - 1)
	{
		dst[i] = src[i - tamanhodest];
		i++;
	}
	if (tamanhodest < size)
		dst[i] = '\0';
	return (tamanhodest + tamanhosrc);
}
/*int main() {
		char destino[20] = "banana";
		char origem[] = "lala";

		size_t tamanho_inicial = ft_strlen(destino);

		size_t tamanho_resultante = ft_strlcat(destino, origem, 1);

		printf("String de destino após strlcat: %s\n", destino);
		printf("Tamanho inicial: %zu\n", tamanho_inicial);
		printf("Tamanho concatenado: %zu\n", tamanho_resultante);

		return 0;
}*/