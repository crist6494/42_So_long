/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 19:55:23 by cmorales          #+#    #+#             */
/*   Updated: 2022/11/30 19:38:59 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*tran;
	size_t			pos;

	tran = (unsigned char *)s;
	pos = 0;
	while (pos < n)
	{
		tran[pos] = 0;
		pos++;
	}
}
/* 
int	main()
{
	char c[50] = "HOLA";
	printf("%s",ft_bzero(c, 2));
	return (0);
} */
