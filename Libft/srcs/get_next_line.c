/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzaccari <rzaccari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 17:27:55 by rzaccari          #+#    #+#             */
/*   Updated: 2023/01/17 20:28:09 by rzaccari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*get_next_line(int fd)
{
	static char	*string[4095];
	char		buffer[BUFFER_SIZE + 1];
	int			read_bytes;

	if (fd < 0 || fd > 4095 || BUFFER_SIZE <= 0)
		return (NULL);
	if (string[fd] && has_line(string[fd]) == 1)
		return (get_line(string, fd));
	read_bytes = read(fd, buffer, BUFFER_SIZE);
	if (read_bytes < 0)
	{
		free(string[fd]);
		return (NULL);
	}
	buffer[read_bytes] = '\0';
	while (read_bytes > 0)
	{
		string[fd] = ft_gnl_strjoin(string[fd], buffer);
		if (has_line(string[fd]) == 1)
			break ;
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		buffer[read_bytes] = '\0';
	}
	return (get_line(string, fd));
}

char	*get_line(char **str, int fd)
{
	char	*line;
	char	*temp;
	int		i;

	i = 0;
	if (str == NULL || str[fd] == NULL)
	{
		free(str[fd]);
		return (NULL);
	}
	while (str[fd][i] != '\0' && str[fd][i] != '\n')
		i++;
	line = ft_gnl_strndup(str[fd], 0, i);
	if (has_line(str[fd]) == 0)
		temp = NULL;
	else
		temp = ft_gnl_strndup(str[fd], i + 1, ft_gnl_strlen(str[fd]));
	free(str[fd]);
	str[fd] = temp;
	return (line);
}

int	has_line(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

// #include <fcntl.h>

// int main(void)
// {
// 	int fd = open("../../includes/maps/map.ber", O_RDONLY);
// 	printf("fd:%d\n", fd);
// 	char	*tmp = get_next_line(fd);
// 	printf("%s", tmp);
// 	free(tmp);
// 	close(fd);
// }