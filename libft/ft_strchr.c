/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfreire <alfreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 14:50:29 by alfreire          #+#    #+#             */
/*   Updated: 2023/10/20 14:03:22 by alfreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	return (ft_memchr(str, c, ft_strlen(str) + 1));
}

// // int main(void)
// // {
// // 		const char  *str = "Hello, world!";
// // 		char    search_char = 'o';
// // 		char    *result = ft_strchr(str, search_char);

// // 		if (result != NULL)
// // 				printf("Caracter '%c' encontrado na posicao: %ld\n", 
// 					search_char, result - str);
// // 		return (0);
// // }