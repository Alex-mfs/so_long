/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfreire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 12:58:59 by alfreire          #+#    #+#             */
/*   Updated: 2023/10/02 13:38:46 by alfreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
	{
		return (1);
	}
	return (0);
}
/*
int	main(void)
{
	char test;
	
	test = 'A';
	if (ft_isalpha(test))
		printf("eh letra\n");
	else
		printf("nao eh letra\n");
	test = '5';
	if (ft_isalpha(test))
		printf("eh letra");
	else
		printf("nao eh letra");
	return (0);
}*/
