/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzaccari <rzaccari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 22:22:08 by rzaccari          #+#    #+#             */
/*   Updated: 2023/01/25 23:23:02 by rzaccari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_adjacent(t_maps *maps, int x, int y)
{
	char		**map;

	map = maps->map_data;
	if (map[y][x] == 'P' || map[y][x] == 'E'
	|| map[y][x] == 'C')
		maps->count++;
	if (map[y][x] != '1')
		map[y][x] = 'B';
	return (0);
}

void	recursive_path(t_maps *maps, int x, int y)
{
	char	**map;

	map = maps->map_data;
	if (map[y][x] == '1' || map[y][x] == 'B')
		return ;
	check_adjacent(maps, x, y);
	recursive_path(maps, x, y - 1);
	recursive_path(maps, x + 1, y);
	recursive_path(maps, x, y + 1);
	recursive_path(maps, x - 1, y);
}

void	check_amount(t_maps *maps, int i, int j)
{
	if (maps->count != maps->coins + 2)
	{
		maps->count = 0;
		recursive_path(maps, j, i);
	}
}

void	check_coins(t_maps *maps)
{
	char	**map;
	int		i;
	int		j;

	map = maps->map_data;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C' || map[i][j] == 'E')
				check_amount(maps, i, j);
			j++;
		}
		i++;
	}
	if (maps->count != maps->coins + 2)
	{
		ft_printf("La map n'est pas faisable...\nClosing...");
		close_window(maps);
	}
	load_map(maps, maps->file);
}

int	count_coins(char **map)
{
	int	i;
	int	j;
	int	coins;

	coins = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				coins++;
			j++;
		}
		i++;
	}
	return (coins);
}
