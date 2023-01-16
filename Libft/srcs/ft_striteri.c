/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzaccari <rzaccari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 15:49:16 by rzaccari          #+#    #+#             */
/*   Updated: 2023/01/16 15:44:46 by rzaccari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_striteri(char *str, void (*f)(unsigned int, char*))
{
	int	i;
	int	strlen;

	if (!str)
		return ;
	i = 0;
	strlen = ft_strlen(str);
	while (i < strlen)
	{
		f(i, &str[i]);
		i++;
	}
}
