/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzaccari <rzaccari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 16:17:44 by rzaccari          #+#    #+#             */
/*   Updated: 2023/01/16 15:44:39 by rzaccari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memset(void *ptr, int val, size_t len)
{
	unsigned char	*str;
	int				i;

	str = ptr;
	i = 0;
	while (len--)
		str[i++] = val;
	return (ptr);
}
