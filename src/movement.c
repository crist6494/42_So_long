/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 18:36:32 by cmorales          #+#    #+#             */
/*   Updated: 2022/12/01 18:43:36 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

void	collect(t_game *game, int x, int y)
{
	int	count;

	count = 0;
	while (game->map.tour[y])
	{
		x = 0;
		while (game->map.tour[y][x] != '\0')
		{
			if (game->map.tour[y][x] == 'C' && x == game->p_x && y == game->p_y
				&& game->img.key->instances[count].enabled == true)
			{
				game->points++;
				game->img.key->instances[count].enabled = false;
				printf("pasos: %d, puntos: %d\n", (game->steps), game->points);
				if (game->points == game->map.count_c)
					change_all_doors(1, game);
			}
			if (game->map.tour[y][x] == 'C')
				count++;
			x++;
		}
		y++;
	}
	finish_game(game);
}

void	move(int n, int sign, t_game *game)
{
	int	x;
	int	y;

	game->steps++;
	x = 0;
	y = 0;
	move_person(n, sign, game);
	if ((game->map.tour[game->p_y + (n == 1) * sign / 64][game->p_x
			+ (n == 2) * sign / 64] != 'C'))
		printf("pasos: %d, puntos: %d\n", (game->steps), game->points);
}

void	movement(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	(void)keydata;
	game = param;
	game->p_y = game->img.player_r->instances[0].y / 64;
	game->p_x = game->img.player_r->instances[0].x / 64;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
	{
		mlx_close_window(game->mlx);
		exit(EXIT_FAILURE);
	}
	else if (mlx_is_key_down(game->mlx, MLX_KEY_W)
		&& game->map.tour[game->p_y - 1][game->p_x] != '1')
		move(1, -64, game);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_S)
		&& game->map.tour[game->p_y + 1][game->p_x] != '1')
		move(1, +64, game);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_A)
		&& game->map.tour[game->p_y][game->p_x - 1] != '1')
		move(2, -64, game);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_D)
		&& game->map.tour[game->p_y][game->p_x + 1] != '1')
		move(2, +64, game);
	collect(game, 0, 0);
}
