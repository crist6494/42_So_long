/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 19:52:44 by cmorales          #+#    #+#             */
/*   Updated: 2022/11/16 20:59:20 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

void ft_void(void)
{
	system("leaks -q so_long");
}

int main (int argc, char **argv)
{
	(void)argc;
	t_game game;

	//atexit(ft_void);
	ft_bzero(&game, sizeof(t_game));
	check_map(&game.map, argv[1]);
	game.img_size = 64;
	//printf("%d\n", game.map.size_x);
	//printf("%d\n", game.map.size_y);
	//printf("%d\n", game.img_size);	
	game.mlx = mlx_init(game.img_size * game.map.size_x, game.img_size * game.map.size_y, "SO_LONG", true);
	if (!game.mlx)
		exit(EXIT_FAILURE);
	load_img(&game); 
	create_map(&game,game.img_size, game.img);
	mlx_key_hook(game.mlx, &movement, (void *)(&game));
	mlx_loop(game.mlx);
	delete_img(&game);
	mlx_terminate(game.mlx); 
	//Borrar los ._ y los .DS_Store
}
