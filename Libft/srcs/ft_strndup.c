/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzaccari <rzaccari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 17:27:47 by rzaccari          #+#    #+#             */
/*   Updated: 2023/01/16 16:00:33 by rzaccari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strndup(char *str, int start, int end)
{
	char	*copy;
	int		i;

	i = 0;
	if (end < start || start < 0 || (int)ft_strlen(str) <= start)
		return (NULL);
	if (end > (int)ft_strlen(str))
		end = ft_strlen(str) - 1;
	copy = (char *)malloc((end - start + 2) * sizeof(char));
	if (!copy)
		return (NULL);
	while (start <= end)
		copy[i++] = str[start++];
	copy[i] = '\0';
	return (copy);
}
