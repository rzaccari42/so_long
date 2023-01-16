/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzaccari <rzaccari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 13:22:03 by rzaccari          #+#    #+#             */
/*   Updated: 2023/01/16 15:44:51 by rzaccari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	unsigned int	i;

	if (n == 0)
		return (0);
	i = 0;
	while (*str1 && *str2 && (*str1 == *str2) && i < (n - 1))
	{
		str1++;
		str2++;
		i++;
	}
	return (*(unsigned char *)str1 - *(unsigned char *)str2);
}
