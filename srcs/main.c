/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzaccari <rzaccari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 19:00:50 by rzaccari          #+#    #+#             */
/*   Updated: 2023/01/25 23:52:49 by rzaccari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_game(t_maps *map, char **av)
{
	map->file = av[1];
	map->item_player = 0;
	map->moves_count = 0;
	get_player_position(map);
	map->coins = count_coins(map->map_data);
	check_coins(map);
	map->mlx = mlx_init();
	map->mlx_win = mlx_new_window(map->mlx, map->map_width * SPRITE, \
		map->map_height * SPRITE, "so_long");
	load_img(map);
	display_map(map);
	mlx_key_hook(map->mlx_win, key_hook, map);
	mlx_hook(map->mlx_win, 17, 1L << 0, close_window, map);
	mlx_loop(map->mlx);
}

int	close_window(t_maps *map)
{
	(void)map;
	exit(0);
}

int	check_extension(char **argv, int size_argv)
{
	int	res;

	res = 0;
	if (argv[1][size_argv - 4] != '.')
		res = 1;
	if (argv[1][size_argv - 3] != 'b')
		res = 1;
	if (argv[1][size_argv - 2] != 'e')
		res = 1;
	if (argv[1][size_argv - 1] != 'r')
		res = 1;
	return (res);
}

int	check_arg(t_maps *map, int argc, char **argv)
{
	int	size_argv;

	if (argc != 2)
	{
		ft_printf("Error\nVeuillez charger UNE map.\n");
		close_window(map);
	}
	size_argv = 0;
	while (argv[1][size_argv] != '\0')
		size_argv ++;
	if (check_extension(argv, size_argv) == 1)
	{
		ft_printf("Error\nProbleme d'extension de map.\n");
		close_window(map);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_maps	map;

	map.map_data = NULL;
	check_arg(&map, argc, argv);
	if (get_map_width(&map, argv) == 1)
	{
		ft_printf("Error\nChemin invalide");
		close_window(&map);
	}
	if (get_map_height(&map, argv) == 1)
	{
		ft_printf("Error\nChemin invalide");
		close_window(&map);
	}
	if (load_map(&map, argv[1]) == 1)
	{
		ft_printf("Error\nChemin invalide");
		close_window(&map);
	}
	map.item_count = 0;
	get_item_number(&map);
	if (!parse_map(&map))
		close_window(&map);
	init_game(&map, argv);
}
