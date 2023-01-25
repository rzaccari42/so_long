/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_x_lower.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzaccari <rzaccari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 14:58:28 by rzaccari          #+#    #+#             */
/*   Updated: 2023/01/23 02:55:19 by rzaccari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	format_x_lower(t_input *args)
{
	char	*lower_x;
	int		i;

	lower_x = itoa_hex_lower(va_arg(args->arguments, unsigned int));
	i = 0;
	while (lower_x[i])
		args->char_count += write(1, &lower_x[i++], 1);
	free(lower_x);
}

char	*itoa_hex_lower(unsigned int nbr)
{
	char	*base;
	char	*str;
	int		i;
	int		rem;

	base = "0123456789abcdef";
	str = malloc((nbrlen_hex(nbr) + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	i = nbrlen_hex(nbr);
	str[i] = 0;
	if (nbr == 0)
	{
		rem = (nbr % 16);
		str[--i] = base[rem];
	}
	while (nbr > 0)
	{
		rem = (nbr % 16);
		str[--i] = base[rem];
		nbr /= 16;
	}
	return (str);
}

int	nbrlen_hex(unsigned int nbr)
{
	int	i;

	i = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
	{
		nbr /= -16;
		i = 2;
	}
	while (nbr > 0)
	{
		nbr /= 16;
		i++;
	}
	return (i);
}
