/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 18:36:32 by cmorales          #+#    #+#             */
/*   Updated: 2022/11/16 20:43:47 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"


void movement(mlx_key_data_t keydata, void* param)
{
	t_game *game;

	(void)keydata;
	game = param;
	game->p_x = game->img.player->instances[0].x / 64;
	game->p_y = game->img.player->instances[0].y / 64;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);
	if (mlx_is_key_down(game->mlx, MLX_KEY_W) && game->map.tour[game->p_y - 1][game->p_x] != '1')
		game->img.player->instances[0].y -= 64;
	if (mlx_is_key_down(game->mlx, MLX_KEY_S) && game->map.tour[game->p_y + 1][game->p_x] != '1')
		game->img.player->instances[0].y += 64;
	if (mlx_is_key_down(game->mlx, MLX_KEY_A) && game->map.tour[game->p_y][game->p_x - 1] != '1')
		game->img.player->instances[0].x -= 64;
	if (mlx_is_key_down(game->mlx, MLX_KEY_D) && game->map.tour[game->p_y][game->p_x + 1] != '1')
		game->img.player->instances[0].x += 64;

}
