/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 18:36:32 by cmorales          #+#    #+#             */
/*   Updated: 2022/11/17 21:59:36 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

void	change_all_doors(t_game *game, int boolean)
{
	int i = 0;
	while(i < game->map.count_e)
	{
		if(boolean == 0)
		{
			game->img.exit_b->instances[i].enabled = false;
			game->img.exit_s->instances[i].enabled = false;
		}
		else
		{
			if(boolean == 1)
				game->img.exit_b->instances[i].enabled = true;
			else
				game->img.exit_s->instances[i].enabled = true;
		}
		i++;
	}
}

void change_image(int n, t_game *game)
{
	if(n < 4)
	{
		game->img.player_r->instances[0].enabled = false;
		game->img.player_l->instances[0].enabled = false;
		game->img.player_f->instances[0].enabled = false;
		game->img.player_b->instances[0].enabled = false;
	}
	else
	{
		change_all_doors(game, 0);
	}
	if(n == 0)
		game->img.player_r->instances[0].enabled = true;
	if(n == 1)
		game->img.player_l->instances[0].enabled = true;
	if(n == 2)
		game->img.player_f->instances[0].enabled = true;
	if(n == 3)
		game->img.player_b->instances[0].enabled = true;
	if(n == 4)
		change_all_doors(game, 1);
	if(n == 5)
		change_all_doors(game, 2);

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
					ft_printf("jamon\n");
					game->points++;
					game->img.key->instances[count].enabled = false;
					return;
				}
				if(game->map.tour[y][x] == 'C')
					count++;
				x++;
			}
			y++;
		}
	}
}

void change_position_of_player(int n, int sign, t_game *game)
{
	if(n == 1)
	{
		game->img.player_r->instances[0].y += sign;
		game->img.player_l->instances[0].y += sign;
		game->img.player_f->instances[0].y += sign;
		game->img.player_b->instances[0].y += sign;
		if(sign < 0)
			change_image(3, game);
		else
			change_image(2, game);
	}
	else
	{
		game->img.player_r->instances[0].x += sign;
		game->img.player_l->instances[0].x += sign;
		game->img.player_f->instances[0].x += sign;
		game->img.player_b->instances[0].x += sign;
		if(sign < 0)
			change_image(1, game);
		else
			change_image(0, game);
	}
}

void movement(mlx_key_data_t keydata, void* param)
{
	t_game *game;
	
	(void)keydata;
	game = param;
	game->steps++;
	game->p_x = game->img.player_r->instances[0].x / 64;
	game->p_y = game->img.player_r->instances[0].y / 64;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_W) && game->map.tour[game->p_y - 1][game->p_x] != '1')
		change_position_of_player(1, -64, game);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_S) && game->map.tour[game->p_y + 1][game->p_x] != '1')
		change_position_of_player(1, +64, game);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_A) && game->map.tour[game->p_y][game->p_x - 1] != '1')
		change_position_of_player(2, -64, game);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_D) && game->map.tour[game->p_y][game->p_x + 1] != '1')
		change_position_of_player(2, +64, game);
	collect(game, 0, 0);
	ft_printf("pasos: %d, puntos: %d\n", game->steps, game->points);
}