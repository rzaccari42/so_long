/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzaccari <rzaccari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 19:00:50 by rzaccari          #+#    #+#             */
/*   Updated: 2023/01/17 19:35:31 by rzaccari         ###   ########.fr       */
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
	display_map();
	map.mlx = mlx_init();
    map.mlx_win = mlx_new_window(map.mlx, 1920, 1080, "so_long");
	load_img(&map);
	put_img(&map, 64, 64, map.img_wall);//revoir pq avec & devant l'image ca passe ap.
	mlx_hook(map.mlx_win, 17, 1L << 0, close_window, &map);
	mlx_loop(map.mlx);
}