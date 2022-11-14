/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 17:37:37 by cmorales          #+#    #+#             */
/*   Updated: 2022/11/02 17:37:47 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

void print_error(char *msg)
{
	write(1, msg, ft_strlen(msg));
	exit(1);
}

int ft_find(char *str, char c)
{
	int i = 0;
	while (str[i])
	{
		if(str[i] == c)
			return (1);
		i++;
	}
	return(0);
}