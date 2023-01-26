/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzaccari <rzaccari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:36:59 by rzaccari          #+#    #+#             */
/*   Updated: 2023/01/25 23:31:51 by rzaccari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	get_map_height(t_maps *map, char **argv)
{
	int		fd;
	int		row_count;
	char	*tmp;

	row_count = 0;
	fd = open(argv[1], O_RDONLY);
	tmp = get_next_line(fd);
	if (tmp == NULL)
		return (1);
	while (tmp)
	{
		free(tmp);
		tmp = get_next_line(fd);
		row_count++;
	}
	free(tmp);
	close(fd);
	map->map_height = row_count;
	return (0);
}

int	get_map_width(t_maps *map, char **argv)
{
	int		fd;
	int		column_count;
	char	*tmp;

	column_count = 0;
	fd = open(argv[1], O_RDONLY);
	tmp = get_next_line(fd);
	if (tmp == NULL)
		return (1);
	while (tmp[column_count])
	{
		column_count++;
	}
	free(tmp);
	close(fd);
	map->map_width = column_count - 1;
	return (0);
}

int	load_map(t_maps *map, char *argv)
{
	int		map_size;
	int		fd;
	int		i;

	map_size = map->map_height;
	fd = open(argv, O_RDONLY);
	map->map_data = (char **)ft_calloc(map_size + 1, sizeof(char *));
	if (map->map_data == NULL)
		return (1);
	i = 0;
	while (i < map->map_height)
	{
		map->map_data[i] = get_next_line(fd);
		i++;
	}
	map->map_data[i] = NULL;
	close(fd);
	return (0);
}

void	get_item_number(t_maps *map)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (map->map_data[i])
	{
		while (map->map_data[i][j])
		{
			if (map->map_data[i][j] == 'C')
				map->item_count++;
			j++;
		}
		i++;
		j = 0;
	}
}

void	display_map(t_maps *map)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (map->map_data[i])
	{
		while (map->map_data[i][j])
		{
			if (map->map_data[i][j] == '1')
				put_img(map, SPRITE * j, SPRITE * i, map->img_wall);
			else if (map->map_data[i][j] == '0')
				put_img(map, SPRITE * j, SPRITE * i, map->img_ground);
			else if (map->map_data[i][j] == 'P')
				put_img(map, SPRITE * j, SPRITE * i, map->img_player);
			else if (map->map_data[i][j] == 'C')
				put_img(map, SPRITE * j, SPRITE * i, map->img_item);
			else if (map->map_data[i][j] == 'E')
				put_img(map, SPRITE * j, SPRITE * i, map->img_exit);
			j++;
		}
		j = 0;
		i++;
	}	
}
