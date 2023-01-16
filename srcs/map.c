/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzaccari <rzaccari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:36:59 by rzaccari          #+#    #+#             */
/*   Updated: 2023/01/16 20:01:51 by rzaccari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "../mlx/mlx.h"

void	display_map()
{
	int		fd;
	char	row;

	fd = open("../uincludes/maps/map.ber", O_RDONLY);
	row = get_next_line(fd);
}