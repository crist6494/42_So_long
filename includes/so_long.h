#ifndef SO_LONG_H
# define SO_LONG_H

# include "../42-library/libft.h"
#include"../MLX42/include/MLX42/MLX42.h"
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <memory.h>
#define WIDTH 256
#define HEIGHT 256


typedef struct	s_map 
{
	int size_x;
	int size_y;
	int count_c;
	int count_p;
	int count_e;
	char **tour;
	char *path;
}t_map;

typedef struct s_img
{
	mlx_image_t *key;
	mlx_image_t *player;
	mlx_image_t *ground;
	mlx_image_t *wall;
	mlx_image_t *exit;
}t_img;

typedef struct	s_game 
{
	int 	p_x;
	int		p_y;
	mlx_t	*mlx;
	int		img_size;
	t_map	map;
	t_img	img;
}t_game;


void print_error(char *msg);
int ft_find(char *str, char c);

int height_of_the_map(t_map *map, char *path);
void read_map(t_map *map, char *path);
void check_map(t_map *map, char *str);
void create_map(t_game *game, int img_size, t_img img);
void load_img(t_game *game);
void delete_img(t_game *game);
void movement(mlx_key_data_t keydata, void* param);
#endif