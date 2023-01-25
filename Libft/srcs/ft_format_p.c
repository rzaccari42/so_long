/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzaccari <rzaccari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 14:58:28 by rzaccari          #+#    #+#             */
/*   Updated: 2023/01/23 02:54:49 by rzaccari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	format_p(t_input *args)
{
	unsigned long long		nbr;
	char					*ptr;
	int						i;

	nbr = va_arg(args->arguments, unsigned long long);
	ptr = itoa_hex_p(nbr);
	args->char_count += write(1, "0x", 2);
	i = 0;
	while (ptr[i])
		args->char_count += write(1, &ptr[i++], 1);
	free(ptr);
}

char	*itoa_hex_p(unsigned long long nbr)
{
	char	*base;
	char	*str;
	int		i;
	int		rem;

	base = "0123456789abcdef";
	str = malloc((nbrlen_hex_p(nbr) + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	i = nbrlen_hex_p(nbr);
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

int	nbrlen_hex_p(unsigned long long nbr)
{
	int	i;

	i = 0;
	if (nbr == 0)
		return (1);
	while (nbr > 0)
	{
		nbr /= 16;
		i++;
	}
	return (i);
}
