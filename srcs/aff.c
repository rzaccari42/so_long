/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzaccari <rzaccari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 23:31:39 by rzaccari          #+#    #+#             */
/*   Updated: 2023/01/25 23:34:05 by rzaccari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	put_img(t_maps *map, int x, int y, void *img)
{
	mlx_put_image_to_window(map->mlx, map->mlx_win, img, x, y);
}

void	load_img(t_maps *map)
{
	map->img_player = mlx_xpm_file_to_image(map->mlx, \
		"./includes/sprites/owl.xpm", &map->img_x, &map->img_y);
	map->img_wall = mlx_xpm_file_to_image(map->mlx, \
		"./includes/sprites/wall.xpm", &map->img_x, &map->img_y);
	map->img_ground = mlx_xpm_file_to_image(map->mlx, \
		"./includes/sprites/grass.xpm", &map->img_x, &map->img_y);
	map->img_item = mlx_xpm_file_to_image(map->mlx, \
		"./includes/sprites/wood_stick.xpm", &map->img_x, &map->img_y);
	map->img_exit = mlx_xpm_file_to_image(map->mlx, \
		"./includes/sprites/exit_empty.xpm", &map->img_x, &map->img_y);
}
