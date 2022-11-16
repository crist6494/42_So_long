/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 20:17:42 by cmorales          #+#    #+#             */
/*   Updated: 2022/11/16 19:35:31 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

void	load_img(t_game *game)
{
	mlx_texture_t *texture;

	texture = mlx_load_png("./assets/img/wall.png");
	game->img.wall = mlx_texture_to_image(game->mlx, texture);
	mlx_delete_texture(texture);
	texture = mlx_load_png("./assets/img/ground2.png");
	game->img.ground = mlx_texture_to_image(game->mlx, texture); 
	mlx_delete_texture(texture);
	texture = mlx_load_png("./assets/img/key.png");
	game->img.key = mlx_texture_to_image(game->mlx, texture); 
	mlx_delete_texture(texture);
	texture = mlx_load_png("./assets/img/pp.png");
	game->img.player = mlx_texture_to_image(game->mlx, texture); 
	mlx_delete_texture(texture);
	texture = mlx_load_png("./assets/img/open-portal2.png");
	game->img.exit = mlx_texture_to_image(game->mlx, texture); 
	mlx_delete_texture(texture);
}

void delete_img(t_game *game)
{
	mlx_delete_image(game->mlx, game->img.wall);
	mlx_delete_image(game->mlx, game->img.ground);
	mlx_delete_image(game->mlx, game->img.key);
	mlx_delete_image(game->mlx, game->img.player);
	mlx_delete_image(game->mlx, game->img.exit);
}