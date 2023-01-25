/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzaccari <rzaccari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:17:20 by rzaccari          #+#    #+#             */
/*   Updated: 2023/01/25 22:34:12 by rzaccari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define SPRITE     64
# define LEFT_KEY	123
# define DOWN_KEY	125
# define RIGHT_KEY	124
# define UP_KEY	    126
# define A_KEY		0
# define S_KEY		1
# define D_KEY		2
# define W_KEY		13
# define ESC        53

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include "../mlx/mlx.h"
# include "../Libft/includes/libft.h"

typedef struct maps
{
	void	*mlx;
	void	*mlx_win;
	char	*map_path;
	char	**map_data;
	char	**map_copy;
	int		map_height;
	int		map_width;
	int		x;
	int		y;
	int		player_x;
	int		player_y;
	int		item_count;
	int		item_player;
	int		moves_count;
	void	*img_player;
	void	*img_wall;
	void	*img_ground;
	void	*img_void;
	void	*img_item;
	void	*img_exit;
	int		exit_x;
	int		exit_y;
	int		img_x;
	int		img_y;
	int		count;
	int		coins;
	char	*file;
}	t_maps;

void	init_game(t_maps *map, char **av);
int		check_arg(t_maps *map, int argc, char **argv);
void	put_img(t_maps *map, int x, int y, void *img);
void	load_img(t_maps *map);
int		get_map_height(t_maps *map, char **argv);
int		get_map_width(t_maps *map, char **argv);
int		load_map(t_maps *map, char *argv);
void	display_map(t_maps *map);
void	get_player_position(t_maps *map);
int		key_hook(int key, t_maps *map);
void	key_process(int key, t_maps *map);
void	move(t_maps *map, int move_x, int move_y);
void	get_item_number(t_maps *map);
int		check_item(t_maps *map);
int		parse_map(t_maps *map);
int		check_map_borders(t_maps *map);
int		close_window(t_maps *map);
int		count_coins(char **map);
void	check_coins(t_maps *maps);
#endif
