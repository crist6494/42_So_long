/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 18:21:34 by cmorales          #+#    #+#             */
/*   Updated: 2022/11/17 21:59:51 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

int height_of_the_map(t_map *map, char *path)
{
	int fd;
	int y;
	char *line;
	y = 0;
	fd = open(path, O_RDONLY);
	if(fd < 0)
		return(0);
	line = get_next_line(fd);
	map->size_x = ft_strlen(line) - 1;
	while(line != 0)
	{
		free(line);
		y++;
		line = get_next_line(fd);
	}
	close(fd);
	free(path);
	return(y);
}

void read_map(t_map *map, char *path)
{
	int fd;
	int y;
	size_t len;
	
	y = 0;
	map->tour = ft_calloc(map->size_y, map->size_x);
	len = map->size_x;
	fd = open(path, O_RDONLY);
	if(fd < 0)
		print_error("Error\nFailed when open the file");
	map->tour[y] = get_next_line(fd);
	while(map->tour[y] != NULL)
	{
		if(len != ft_strlen(map->tour[y]) - 1)
			print_error("Error\nMap is not rectangular");
		y++;
		map->tour[y] = get_next_line(fd);
	}
	close(fd);
}

void load_content_map(t_game *game, int img_size, t_img *img)
{
	int x;
	int y;
	
	y = 0;
	while(y < game->map.size_y)
	{
		x = 0;
		while(x < game->map.size_x)
		{
			if(game->map.tour[y][x] == 'C')
				mlx_image_to_window(game->mlx, img->key, x * img_size, y * img_size);
			if(game->map.tour[y][x] == 'P')
			{
				game->p_x = x;
				game->p_y = y;
				mlx_image_to_window(game->mlx, img->player_r, x * img_size, y * img_size);	
			 	mlx_image_to_window(game->mlx, img->player_l, x * img_size, y * img_size);	
				mlx_image_to_window(game->mlx, img->player_f, x * img_size, y * img_size);	
				mlx_image_to_window(game->mlx, img->player_b, x * img_size, y * img_size);
				change_image(0, game);	  
			}
			if(game->map.tour[y][x] == 'E')
			{
				mlx_image_to_window(game->mlx, img->exit_s, x * img_size, y * img_size);	
				mlx_image_to_window(game->mlx, img->exit_b, x * img_size, y * img_size);
				change_image(4, game);	 
			}
			x++;
		}
		y++;
	}
}

void create_map(t_game *game, int img_size, t_img *img)
{
	int x;
	int y;
	
	y = 0;
	load_img(game);
	while(y < game->map.size_y)
	{
		x = 0;
		while(x < game->map.size_x)
		{
			if (ft_strchr("10ECP", game->map.tour[y][x]))
				mlx_image_to_window(game->mlx, img->ground, x * img_size, y * img_size); 
			if(game->map.tour[y][x] == '1')
				mlx_image_to_window(game->mlx, img->wall, x * img_size, y * img_size);
			x++;
		}
		y++;
	}
	load_content_map(game, img_size, img);
}

