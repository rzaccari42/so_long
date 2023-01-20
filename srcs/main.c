/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzaccari <rzaccari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 19:00:50 by rzaccari          #+#    #+#             */
/*   Updated: 2023/01/20 22:19:13 by rzaccari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	close_window(t_maps *map)
{
	(void)map;
	exit(0);
}

int	main(void)
{
	t_maps map;
	int	i;

	i = 10;
	map.mlx = mlx_init();
    map.mlx_win = mlx_new_window(map.mlx, get_map_widht() * SPRITE, get_map_height() * SPRITE, "so_long");
	load_map();
	display_map(&map);
	mlx_key_hook(map.mlx_win, key_action, &map);
	mlx_hook(map.mlx_win, 17, 1L << 0, close_window, &map);
	mlx_loop(map.mlx);
}