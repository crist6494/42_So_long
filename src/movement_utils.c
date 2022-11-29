/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 19:39:22 by cmorales          #+#    #+#             */
/*   Updated: 2022/11/29 20:44:11 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

void	change_all_doors(int f, t_game *game)
{
	int	i;
	int	max_doors;

	i = 0;
	max_doors = game->map.count_e - 1;
	while (i <= max_doors)
	{
		if (f == 0)
		{
			game->img.exit[0]->instances[i].enabled = true;
			game->img.exit[1]->instances[i].enabled = false;
		}
		if (f == 1)
		{
			game->img.exit[0]->instances[i].enabled = false;
			game->img.exit[1]->instances[i].enabled = true;
		}
		i++;
	}
}

void	change_person_img(int n, t_game *game)
{
	game->img.player_r->instances[0].enabled = false;
	game->img.player_l->instances[0].enabled = false;
	game->img.player_f->instances[0].enabled = false;
	game->img.player_b->instances[0].enabled = false;
	if (n == 0)
		game->img.player_r->instances[0].enabled = true;
	if (n == 1)
		game->img.player_l->instances[0].enabled = true;
	if (n == 2)
		game->img.player_f->instances[0].enabled = true;
	if (n == 3)
		game->img.player_b->instances[0].enabled = true;
}

void	move_person(int n, int sign, t_game *game)
{
	if (n == 1)
	{
		game->img.player_r->instances[0].y += sign;
		game->img.player_l->instances[0].y += sign;
		game->img.player_f->instances[0].y += sign;
		game->img.player_b->instances[0].y += sign;
		if (sign < 0)
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
		if (sign < 0)
			change_person_img(1, game);
		else
			change_person_img(0, game);
	}
}

void	finish_game(t_game *game)
{
	if (game->points == game->map.count_c)
	{
		if (game->map.tour[game->p_y][game->p_x] == 'E')
		{
			ft_printf("\e[32;1mYOU WIN!\e[0m\n");
			delete_img(game);
			mlx_terminate(game->mlx);
			exit(EXIT_SUCCESS);
		}
	}
}
