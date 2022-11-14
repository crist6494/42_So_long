/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 18:01:45 by cmorales          #+#    #+#             */
/*   Updated: 2022/10/26 18:12:15 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include "../MLX42/include/MLX42/MLX42.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <memory.h>
#define WIDTH 1920
#define HEIGHT 1080

mlx_image_t	*g_img;
mlx_texture_t* fondo;
mlx_texture_t* mario;

void clear()
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
			mlx_put_pixel(g_img, x++, y, 0xffffffff);
		y++;
	}
}

void	hook(void *param)
{
	mlx_t	*mlx;
	static int x = 500;
	static int y = 500;

	mlx = param;
	clear();
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_UP) && y > 0)
		y -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_DOWN) && 5 + y < HEIGHT)
		y += 5;
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
		x -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
		x += 5;
	mlx_draw_texture(g_img, fondo, 0, 0);
	mlx_draw_texture(g_img, mario, x, y);

}

int32_t	main(void)
{
	mlx_t	*mlx;

	mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	if (!mlx)
		exit(EXIT_FAILURE);
	g_img = mlx_new_image(mlx, WIDTH, HEIGHT);
	fondo = mlx_load_png("./572107.png");
	mario = mlx_load_png("./mario03.png");
	mlx_image_to_window(mlx, g_img, 0, 0);
	mlx_loop_hook(mlx, &hook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
 */