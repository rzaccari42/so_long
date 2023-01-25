/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzaccari <rzaccari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 21:44:00 by rzaccari          #+#    #+#             */
/*   Updated: 2023/01/25 23:35:13 by rzaccari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	get_player_position(t_maps *map)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (map->map_data[i])
	{
		while (map->map_data[i][j])
		{
			if (map->map_data[i][j] == 'P')
			{
				map->player_x = j;
				map->player_y = i;
			}
			j++;
		}
		i++;
		j = 0;
	}
}

void	move_exit(t_maps *map, char next_pos)
{
	if (next_pos == 'E')
	{
		if (check_item(map) == 1)
		{
			map->moves_count++;
			ft_printf("PARTIE TERMINÉE !\nNombre de déplacements : %i\n", \
				map->moves_count);
			close_window(map);
		}
	}
}

void	move(t_maps *map, int move_x, int move_y)
{
	char	next_pos;

	next_pos = map->map_data[map->player_y + move_y][map->player_x + move_x];
	if (next_pos == '0' || next_pos == 'C' || next_pos == 'P')
	{
		if (next_pos == 'C')
		{
			map->item_player++;
			map->map_data[map->player_y + move_y][map->player_x + move_x] = '0';
		}
		put_img(map, SPRITE * map->player_x, SPRITE * map->player_y, \
			map->img_ground);
		map->player_x += move_x;
		map->player_y += move_y;
		put_img(map, SPRITE * map->player_x + move_x, \
			SPRITE * map->player_y + move_y, map->img_player);
		map->moves_count++;
		ft_printf("Déplacements : %i\r", map->moves_count);
	}
	move_exit(map, next_pos);
}

void	key_process(int key, t_maps *map)
{
	if (key == UP_KEY || key == W_KEY)
		move(map, 0, -1);
	if (key == DOWN_KEY || key == S_KEY)
		move(map, 0, +1);
	if (key == LEFT_KEY || key == A_KEY)
		move(map, -1, 0);
	if (key == RIGHT_KEY || key == D_KEY)
		move(map, +1, 0);
	if (key == ESC)
		close_window(map);
}

int	key_hook(int key, t_maps *map)
{
	key_process(key, map);
	return (0);
}
