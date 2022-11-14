/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 18:59:16 by cmorales          #+#    #+#             */
/*   Updated: 2022/11/14 17:44:31 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

void check_args(t_map *map)
{
	char	*suffix;
	int		len;

	suffix = 0;
	
		len = ft_strlen(map->path);
		suffix = ft_substr(map->path, len - 4 , len);
		if(!suffix)
			return ; 
		if(ft_find(map->path, '.'))
		{
			if (ft_strncmp(".ber", suffix, ft_strlen(suffix)))
			{
				free(suffix);
				print_error("Error\nIncorrect filename");
			}	
		}
		else
			print_error("Error\nIncorrect filename");

	free(suffix);
}


void check_border_map(t_map *map, char **tour)
{
	int x;
	int y;
	y = 0;
	while(y < map->size_y)
	{
		x = 0;
		while(x < map->size_x)
		{
			if (y == 0 || y == map->size_y )
			{
				if(tour[y][x] != '1')
				{
					//printf("%d\n", x);
					//printf("%d", y);
					print_error("Error\nMap  is not enclosed by walls\n"); 
				}
			}
			else if ((y > 0 && y < map->size_y) && (x == 0 || x == map->size_x - 1))
			{
				if(tour[y][x] != '1')
				{
					//printf("%d", x);
					//printf("%d\n", y);
					print_error("Error\nMap  is not enclosed by walls\n"); 
				}
			}
			x++;
		}
		y++;
	}
}

void check_content_map(t_map *map, char **tour)
{
	int x;
	int y;

	y = 0;
	map->count_e = 0;
	map->count_p = 0;
	map->count_c = 0;
	while(y < map->size_y)
	{
		x = 0;
		while (x < map->size_x)
		{
			if(tour[y][x] == 'C')
				map->count_c++;
			else if(tour[y][x] == 'E')
				map->count_e++;
			else if(tour[y][x] == 'P')
				map->count_p++;
			x++;
		}
		y++;
	}

	if(map->count_c < 1 || map->count_e < 1 || map->count_p < 1)
		print_error("Error\nMissing elements in the map\n");
	if(map->count_p != 1)
		print_error("Error\nOnly one player can be in the map\n");
}

void check_map(t_map *map, char *str)
{
	map->path = ft_strjoin("assets/map/", str);
	check_args(map);
	map->size_y = height_of_the_map(map, map->path);
	read_map(map, map->path);
	//printf("%d\n", map->size_y);
	//printf("%d", map->size_x);
	check_border_map(map, map->tour);
	check_content_map(map, map->tour);
}



