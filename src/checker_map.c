/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 18:59:16 by cmorales          #+#    #+#             */
/*   Updated: 2022/12/01 18:53:03 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

void	check_args(t_map *map)
{
	char	*suffix;
	int		len;

	suffix = 0;
	len = ft_strlen(map->path);
	suffix = ft_substr(map->path, len - 4, len);
	if (!suffix)
		return ;
	if (ft_find(map->path, '.'))
	{
		if (ft_strncmp(".ber", suffix, ft_strlen(suffix)))
		{
			free(suffix);
			print_error("\033[0;31mError\nIncorrect filename\n");
		}
	}
	else
		print_error("\033[0;31mError\nIncorrect filename\n");
	free(suffix);
}

void	check_border_map(t_map *map, char **tour)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->size_y)
	{
		x = 0;
		while (x < map->size_x)
		{
			if (y == 0 || y == map->size_y)
			{
				if (tour[y][x] != '1')
					print_error("\033[0;31mError\nMap is not enclosed by walls\n");
			}
			else if ((y > 0 && y < map->size_y)
				&& (x == 0 || x == map->size_x - 1))
			{
				if (tour[y][x] != '1')
					print_error("\033[0;31mError\nMap is not enclosed by walls\n");
			}
			x++;
		}
		y++;
	}
}

void	check_content_map(t_map *map, char **tour)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->size_y)
	{
		x = 0;
		while (x < map->size_x)
		{
			if (tour[y][x] == 'C')
				map->count_c++;
			else if (tour[y][x] == 'E')
				map->count_e++;
			else if (tour[y][x] == 'P')
				map->count_p++;
			x++;
		}
		y++;
	}
	if (map->count_c < 1 || map->count_e < 1 || map->count_p < 1)
		print_error("\033[0;31mError\nMissing elements in the map\n");
	if (map->count_p != 1)
		print_error("\033[0;31mError\nOnly one player can be in the map\n");
}

void	check_map(t_map *map, char *str)
{
	map->count_c = 0;
	map->count_e = 0;
	map->count_p = 0;
	map->path = ft_strjoin("assets/map/", str);
	check_args(map);
	map->size_y = height_of_the_map(map, map->path);
	read_map(map, map->path);
	check_border_map(map, map->tour);
	check_content_map(map, map->tour);
	free(map->path);
}
