#ifndef SO_LONG_H
# define SO_LONG_H

# include "../42-library/libft.h"
#include"../MLX42/include/MLX42/MLX42.h"
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <memory.h>

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
	mlx_image_t *player_r;
	mlx_image_t *player_l;
	mlx_image_t *player_f;
	mlx_image_t *player_b;
	mlx_image_t *ground;
	mlx_image_t *wall;
	mlx_image_t **exit;
}t_img;

typedef struct	s_game 
{
	int 	p_x;
	int		p_y;
	mlx_t	*mlx;
	int		img_size;
	t_map	map;
	t_img	img;
	int		steps;
	int		points;
}t_game;


/*--------Checker_map------------*/
void	check_args(t_map *map);
void	check_border_map(t_map *map, char **tour);
void	check_content_map(t_map *map, char **tour);
void	check_map(t_map *map, char *str);

/*----------Map------------*/
int		height_of_the_map(t_map *map, char *path);
void	read_map(t_map *map, char *path);
void	create_map(t_game *game, int img_size, t_img *img);

/*----------Img------------*/
void	load_env(t_game *game);
void	load_p(t_game *game);
void	delete_img(t_game *game);

/*--------Movement------------*/
void	collect(t_game *game, int x, int y);
void	move(int n, int sign, t_game *game);
void	movement(mlx_key_data_t keydata, void* param);

/*--------Movements_Utils------------*/
void	change_all_doors(int f, t_game *game);
void	change_person_img(int n, t_game *game);
void	move_person(int n, int sign, t_game *game);
void	finish_game(t_game *game);

/*--------Utils------------*/
void	ft_void(void);
void 	free_map(char **map);
void	print_error(char *msg);
int		ft_find(char *str, char c);
void ft_exit(void);

#endif