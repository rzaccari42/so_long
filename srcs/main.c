/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzaccari <rzaccari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 19:00:50 by rzaccari          #+#    #+#             */
/*   Updated: 2023/01/13 22:42:26 by rzaccari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include <stdio.h>
#include <unistd.h>

typedef struct game
{
	char	*map;
	int		i;
	int		carater;
	int		colone;
	int		colone_temp;
	int		ligne;
	int		ligne_temp;
	int		player;
	int		diams;
	int		exit;
	int		erreur;
	void	*mlx;
	void	*mlx_win;
	void	*mlx_player;
	void	*mlx_mur;
	void	*mlx_sol;
	void	*mlx_vide;
	void	*mlx_diams;
	void	*mlx_door;
}	t_game;


/*void	my_mlx_pixel_put(t_image *img, int x, int y, int color)
{
	char	*dst;

	dst = img->pixels + (y * img->line_size + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}*/

int	main(void)
{
	t_game data;
	int	i;

	data.mlx = mlx_init();
    data.mlx_win = mlx_new_window(data.mlx, 1920, 1080, "so_long");
	//img.ptr = mlx_new_image(mlx, 1920, 1080);
	//my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	data.mlx_mur = mlx_xpm_file_to_image(data.mlx, "./includes/wall-01.xpm", &i, &i);
	mlx_put_image_to_window(data.mlx, data.mlx_win, data.mlx_mur, 50, 50);
	mlx_loop(data.mlx);
}
