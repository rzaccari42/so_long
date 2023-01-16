/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzaccari <rzaccari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 14:42:45 by rzaccari          #+#    #+#             */
/*   Updated: 2023/01/16 15:44:08 by rzaccari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;

	p = malloc(sizeof(unsigned char) * (count * size));
	if (p == NULL)
		return (NULL);
	ft_memset(p, 0, size * count);
	return (p);
}
