/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzaccari <rzaccari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 19:21:00 by rzaccari          #+#    #+#             */
/*   Updated: 2023/01/25 23:45:11 by rzaccari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_item(t_maps *map)
{
	if (map->item_player == map->item_count)
		return (1);
	return (0);
}

int	check_map_borders(t_maps *map)
{
	int	i;

	i = map->map_width;
	while (i--)
		if (map->map_data[0][i] != '1' || \
			map->map_data[map->map_height - 1][i] != '1')
			return (0);
	i = map->map_height;
	while (i--)
		if (map->map_data[i][0] != '1' || \
			map->map_data[i][map->map_width - 1] != '1')
			return (0);
	return (1);
}

int	check_map_elements(t_maps *map)
{
	int	player;
	int	exit;
	int	i;
	int	j;

	player = 0;
	exit = 0;
	i = 0;
	j = 0;
	while (map->map_data[i])
	{
		while (map->map_data[i][j])
		{
			if (map->map_data[i][j] == 'P')
				player++;
			else if (map->map_data[i][j] == 'E')
				exit++;
			j++;
		}
		i++;
		j = 0;
	}
	if (map->item_count == 0 || player != 1 || exit != 1)
		return (0);
	return (1);
}

int	check_map_rectangular(t_maps *map)
{
	int	line_lenght;
	int	i;
	int	j;

	line_lenght = map->map_width;
	i = 1;
	while (i < map->map_height)
	{
		j = 0;
		while (map->map_data[i][j] && map->map_data[i][j] != '\n')
		{
			j++;
		}
		if (j != line_lenght)
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int	parse_map(t_maps *map)
{
	if (!check_map_rectangular(map))
	{
		ft_printf("Erreur\nLa map doit être rectangulaire.\n");
		return (0);
	}
	if (!check_map_borders(map))
	{
		ft_printf("Erreur\nLa map n'est pas encadrée par des murs.\n");
		return (0);
	}
	if (!check_map_elements(map))
	{
		ft_printf("Erreur\nLa map doit contenir une position de départ, ");
		ft_printf("une sortie, et au moins un item.\n");
		return (0);
	}
	return (1);
}
