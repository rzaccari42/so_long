/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzaccari <rzaccari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:36:59 by rzaccari          #+#    #+#             */
/*   Updated: 2023/01/17 20:42:43 by rzaccari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	put_img(t_maps *map, int x, int y, void *img)
{
	mlx_put_image_to_window(map->mlx, map->mlx_win, img, x, y);
}

void	load_img(t_maps *map)
{
	map->img_wall = mlx_xpm_file_to_image(map->mlx, "./includes/sprites/wall.xpm", &map->img_x, &map->img_y);
}

int	get_map_size()
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

void	display_map()
{
	char	**map;
	int		map_size;
	int		fd;
	int		i;

	map_size = get_map_size();
	printf("map size:%d\n", map_size);
	printf("%i", map_size);
	fd = open("./includes/maps/map.ber", O_RDONLY);
	printf("fd:%d\n", fd);
	map = (char **)ft_calloc(map_size + 1, sizeof(char *));
	i = 0;
	while (i < map_size)
	{
		map[i] = get_next_line(fd);
		i++;
	}
	map[i] = NULL;
	i = 0;
	while (i < map_size)
	{
		printf("%s", map[i]);
		i++;
	}
	printf("\nslddjflds\n");
}


