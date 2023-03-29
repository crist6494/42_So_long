/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 18:21:34 by cmorales          #+#    #+#             */
/*   Updated: 2023/03/29 19:33:25 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

int	height_of_the_map(t_map *map, char *path)
{
	int		fd;
	int		y;
	char	*line;

	y = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (0);
	line = get_next_line(fd);
	map->size_x = ft_strlen(line) - 1;
	while (line != 0)
	{
		free(line);
		y++;
		line = get_next_line(fd);
	}
	close(fd);
	free(line);
	return (y);
}

void	read_map(t_map *map, char *path)
{
	int		fd;
	int		y;
	size_t	len;

	y = 0;
	map->tour = ft_calloc(map->size_y + 1, map->size_x);
	len = map->size_x;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		print_error("\033[0;31mError\nFailed when open the file\n");
	map->tour[y] = get_next_line(fd);
	while (map->tour[y] != NULL)
	{
		if (len != ft_strlen(map->tour[y]) - 1)
			print_error("\033[0;31mError\nMap is not rectangular\n");
		y++;
		map->tour[y] = get_next_line(fd);
	}
	close(fd);
}

void	load_texture_map(int l, t_game *game, int x, int y)
{
	if (l == 0)
		mlx_image_to_window(game->mlx, game->img.key, x
			* game->img_size, y * game->img_size);
	if (l == 1)
	{
		game->p_x = x;
		game->p_y = y;
		mlx_image_to_window(game->mlx, game->img.player_r, x
			* game->img_size, y * game->img_size);
		mlx_image_to_window(game->mlx, game->img.player_l, x
			* game->img_size, y * game->img_size);
		mlx_image_to_window(game->mlx, game->img.player_f, x
			* game->img_size, y * game->img_size);
		mlx_image_to_window(game->mlx, game->img.player_b, x
			* game->img_size, y * game->img_size);
		change_person_img(0, game);
	}
	if (l == 2)
	{
		mlx_image_to_window(game->mlx, game->img.exit[0], x
			* game->img_size, y * game->img_size);
		mlx_image_to_window(game->mlx, game->img.exit[1], x
			* game->img_size, y * game->img_size);
	}
}

void	load_content_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map.size_y)
	{
		x = 0;
		while (x < game->map.size_x)
		{
			if (game->map.tour[y][x] == 'C')
				load_texture_map(0, game, x, y);
			if (game->map.tour[y][x] == 'P')
				load_texture_map(1, game, x, y);
			if (game->map.tour[y][x] == 'E')
				load_texture_map(2, game, x, y);
			x++;
		}
		y++;
	}
	change_all_doors(0, game);
}

void	create_map(t_game *game, int img_size, t_img *img)
{
	int	x;
	int	y;

	y = 0;
	load_env(game);
	load_p(game);
	while (y < game->map.size_y)
	{
		x = 0;
		while (x < game->map.size_x)
		{
			if (ft_strchr("0CEP", game->map.tour[y][x]))
				mlx_image_to_window(game->mlx, img->ground, x
					* img_size, y * img_size);
			if (game->map.tour[y][x] == '1')
				mlx_image_to_window(game->mlx, img->wall, x
					* img_size, y * img_size);
			x++;
		}
		y++;
	}
	load_content_map(game);
}
