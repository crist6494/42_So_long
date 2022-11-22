/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 18:36:32 by cmorales          #+#    #+#             */
/*   Updated: 2022/11/22 17:36:55 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

void	change_all_doors(int f, t_game *game)
{
	game->img.exit_b->instances[0].enabled = false;
	game->img.exit_s->instances[0].enabled = false;

	if(f == 0)
		game->img.exit_b->instances[0].enabled = true;
	else if (f == 1)	
		game->img.exit_s->instances[0].enabled = true;
}

void change_person_img(int n, t_game *game)
{
	game->img.player_r->instances[0].enabled = false;
	game->img.player_l->instances[0].enabled = false;
	game->img.player_f->instances[0].enabled = false;
	game->img.player_b->instances[0].enabled = false;

	if(n == 0)
		game->img.player_r->instances[0].enabled = true;
	if(n == 1)
		game->img.player_l->instances[0].enabled = true;
	if(n == 2)
		game->img.player_f->instances[0].enabled = true;
	if(n == 3)
		game->img.player_b->instances[0].enabled = true;
}

void	collect(t_game *game, int x, int y)
{
	int count = 0;
	if(game->map.tour[game->p_y][game->p_x] == 'C')
	{
		while(game->map.tour[y])
		{
			x = 0;
			while(game->map.tour[y][x] != '\0')
			{
				if(game->map.tour[y][x] == 'C' && x == game->p_x && y == game->p_y && game->img.key->instances[count].enabled == true)
				{
					game->img.key->instances[count].enabled = false;
					game->points++;
					//return;
				}
				if(game->map.tour[y][x] == 'C')
					count++;
				x++;
			}
			y++;
		}
	}
	else if (game->points == game->map.count_c)
	{
		game->img.exit_s->instances[0].enabled= false;
		game->img.exit_b->instances[0].enabled= true;
		if (game->map.tour[game->p_y][game->p_x] == 'E')
		{
			ft_printf("\e[32;1mYOU WIN!\e[0m\n");
			close_game(game);
		}
	}
}

void move(int n, int sign, t_game *game)
{
	game->steps++;
	if(n == 1)
	{
		game->img.player_r->instances[0].y += sign;
		game->img.player_l->instances[0].y += sign;
		game->img.player_f->instances[0].y += sign;
		game->img.player_b->instances[0].y += sign;
		if(sign < 0)
			change_person_img(3, game);
		else
			change_person_img(2, game);
	}
	else
	{
		game->img.player_r->instances[0].x += sign;
		game->img.player_l->instances[0].x += sign;
		game->img.player_f->instances[0].x += sign;
		game->img.player_b->instances[0].x += sign;
		if(sign < 0)
			change_person_img(1, game);
		else
			change_person_img(0, game);
	}
	ft_printf("pasos: %d, puntos: %d\n", game->steps, game->points);
}

void movement(mlx_key_data_t keydata, void* param)
{
	t_game *game;
	
	(void)keydata;
	game = param;
	game->p_x = game->img.player_r->instances[0].x / 64;
	game->p_y = game->img.player_r->instances[0].y / 64;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_W) && game->map.tour[game->p_y - 1][game->p_x] != '1')
		move(1, -64, game);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_S) && game->map.tour[game->p_y + 1][game->p_x] != '1')
		move(1, +64, game);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_A) && game->map.tour[game->p_y][game->p_x - 1] != '1')
		move(2, -64, game);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_D) && game->map.tour[game->p_y][game->p_x + 1] != '1')
		move(2, +64, game);
	collect(game, 0, 0);
}