/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzaccari <rzaccari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:17:20 by rzaccari          #+#    #+#             */
/*   Updated: 2023/01/20 22:29:48 by rzaccari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define SPRITE 64

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include "../mlx/mlx.h"
# include "../libft/includes/libft.h"

typedef struct maps
{
	void	*mlx;
	void	*mlx_win;
    char	**maps;
    char	**maps_copy;
    int     x;
    int     y;
    int     pos_x;
    int     pos_y;
    int     moves_count;
	void	*img_player;
	void	*img_wall;
	void	*img_ground;
	void	*img_void;
	void	*img_item;
	void	*img_exit;
    int     exit_x;
    int     exit_y;
    int		img_x;
	int		img_y;
}	t_maps;

void	put_img(t_maps *map, int x, int y, void *img);
void	load_img(t_maps *map);
int     get_map_height();
int 	get_map_widht();
char	**load_map();
void	display_map(t_maps *map);
void	key_hook(int key, t_maps *map);


#endif