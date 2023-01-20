/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzaccari <rzaccari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:36:59 by rzaccari          #+#    #+#             */
/*   Updated: 2023/01/20 21:43:00 by rzaccari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	put_img(t_maps *map, int x, int y, void *img)
{
	mlx_put_image_to_window(map->mlx, map->mlx_win, img, x, y);
}

void	load_img(t_maps *map)
{
	map->img_player = mlx_xpm_file_to_image(map->mlx, "./includes/sprites/owl.xpm", &map->img_x, &map->img_y);
	map->img_wall = mlx_xpm_file_to_image(map->mlx, "./includes/sprites/wall.xpm", &map->img_x, &map->img_y);
	map->img_ground = mlx_xpm_file_to_image(map->mlx, "./includes/sprites/grass.xpm", &map->img_x, &map->img_y);
	map->img_item = mlx_xpm_file_to_image(map->mlx, "./includes/sprites/wood_stick.xpm", &map->img_x, &map->img_y);
	map->img_exit = mlx_xpm_file_to_image(map->mlx, "./includes/sprites/exit_empty.xpm", &map->img_x, &map->img_y);
}

int	get_map_height()
{
	int		fd;
	int		row_count;
	char	*tmp;

	row_count = 0;
	fd = open("./includes/maps/map.ber", O_RDONLY);
	tmp = get_next_line(fd);
	while (tmp)
	{
		free(tmp);
		tmp = get_next_line(fd);
		row_count++;
	}
	free(tmp);
	close(fd);
	return (row_count);
}

int	get_map_widht()
{
	int		fd;
	int		collumn_count;
	char	*tmp;

	collumn_count = 0;
	fd = open("./includes/maps/map.ber", O_RDONLY);
	tmp = get_next_line(fd);
	while (tmp[collumn_count])
	{
		collumn_count++;
	}
	free(tmp);
	close(fd);
	return (collumn_count - 1);
}

char	**load_map()
{
	char	**map_data;
	int		map_size;
	int		fd;
	int		i;

	map_size = get_map_height();
	fd = open("./includes/maps/map.ber", O_RDONLY);
	map_data = (char **)ft_calloc(map_size + 1, sizeof(char *));
	i = 0;
	while (i < map_size)
	{
		map_data[i] = get_next_line(fd);
		i++;
	}
	map_data[i] = NULL;
	return (map_data);
}

void	display_map(t_maps *map)
{
	char	**map_data;
	int		i;
	int		j;

	load_img(map);
	map_data = load_map();
	i = 0;
	j = 0;
	while (map_data[i])
	{
		while (map_data[i][j])
		{
			if (map_data[i][j] == '1')
				put_img(map, SPRITE * j, SPRITE * i, map->img_wall);
			else if (map_data[i][j] == '0')
				put_img(map, SPRITE * j, SPRITE * i, map->img_ground);
			else if (map_data[i][j] == 'P')
				put_img(map, SPRITE * j, SPRITE * i, map->img_player);
			else if (map_data[i][j] == 'C')
				put_img(map, SPRITE * j, SPRITE * i, map->img_item);
			else if (map_data[i][j] == 'E')
				put_img(map, SPRITE * j, SPRITE * i, map->img_exit);
			j++;
		}
		j = 0;
		i++;
	}	
}