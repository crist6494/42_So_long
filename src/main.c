/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 19:52:44 by cmorales          #+#    #+#             */
/*   Updated: 2022/12/01 18:55:27 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc > 1)
	{
		mlx_set_setting(MLX_STRETCH_IMAGE, 1);
		ft_bzero(&game, sizeof(t_game));
		check_map(&game.map, argv[1]);
		game.img_size = 64;
		game.points = 0;
		game.steps = 0;
		game.mlx = mlx_init(game.img_size * game.map.size_x, game.img_size
				* game.map.size_y, "SO_LONG", true);
		if (!game.mlx)
			exit(EXIT_FAILURE);
		create_map(&game, game.img_size, &game.img);
		mlx_key_hook(game.mlx, &movement, (void *)(&game));
		mlx_loop(game.mlx);
		mlx_terminate(game.mlx);
		free_map(game.map.tour);
		delete_img(&game);
		ft_exit();
	}
	else
		print_error("\033[0;31mError\nMissing arguments\n");
}
