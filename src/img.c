/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 20:17:42 by cmorales          #+#    #+#             */
/*   Updated: 2022/11/28 18:33:05 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

void	load_img(t_game *game)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png("./assets/img/wall.png");
	game->img.wall = mlx_texture_to_image(game->mlx, texture);
	mlx_delete_texture(texture);
	texture = mlx_load_png("./assets/img/ground2.png");
	game->img.ground = mlx_texture_to_image(game->mlx, texture);
	mlx_delete_texture(texture);
	texture = mlx_load_png("./assets/img/key1.png");
	game->img.key = mlx_texture_to_image(game->mlx, texture);
	mlx_delete_texture(texture);
	
	texture = mlx_load_png("./assets/img/derecha.png");
	game->img.player_r = mlx_texture_to_image(game->mlx, texture);
	mlx_delete_texture(texture);
	texture = mlx_load_png("./assets/img/izquierda.png");
	game->img.player_l = mlx_texture_to_image(game->mlx, texture);
	mlx_delete_texture(texture);
	texture = mlx_load_png("./assets/img/frente.png");
	game->img.player_f = mlx_texture_to_image(game->mlx, texture);
	mlx_delete_texture(texture);
	texture = mlx_load_png("./assets/img/espalda.png");
	game->img.player_b = mlx_texture_to_image(game->mlx, texture);
	mlx_delete_texture(texture);
	
	game->img.exit = malloc(sizeof(mlx_image_t) * 2);
	texture = mlx_load_png("./assets/img/portal2.png");
	game->img.exit[0] = mlx_texture_to_image(game->mlx, texture);
	mlx_delete_texture(texture);
	texture = mlx_load_png("./assets/img/portal.png");
	game->img.exit[1] = mlx_texture_to_image(game->mlx, texture);
	mlx_delete_texture(texture);
}

void	delete_img(t_game *game)
{
	mlx_delete_image(game->mlx, game->img.wall);
	mlx_delete_image(game->mlx, game->img.ground);
	mlx_delete_image(game->mlx, game->img.key);
	mlx_delete_image(game->mlx, game->img.player_r);
	mlx_delete_image(game->mlx, game->img.player_l);
	mlx_delete_image(game->mlx, game->img.player_f);
	mlx_delete_image(game->mlx, game->img.player_b);
	mlx_delete_image(game->mlx, *game->img.exit);
}
