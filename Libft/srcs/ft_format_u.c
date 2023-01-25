/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzaccari <rzaccari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 14:58:28 by rzaccari          #+#    #+#             */
/*   Updated: 2023/01/23 02:55:07 by rzaccari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	format_u(t_input *args)
{
	char	*u;
	int		i;

	u = itoa_unsigned(va_arg(args->arguments, unsigned int));
	i = 0;
	while (u[i])
		args->char_count += write(1, &u[i++], 1);
	free(u);
}

char	*itoa_unsigned(unsigned int nbr)
{
	char			*str;
	int				i;

	str = malloc((nbrlen_unsigned(nbr) + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	i = nbrlen_unsigned(nbr);
	str[i] = 0;
	if (nbr == 0)
		str[--i] = (nbr % 10) + 48;
	while (nbr > 0)
	{
		str[--i] = (nbr % 10) + 48;
		nbr /= 10;
	}
	return (str);
}

int	nbrlen_unsigned(unsigned int nbr)
{
	int	i;

	i = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
	{
		nbr /= -10;
		i = 2;
	}
	while (nbr > 0)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}
