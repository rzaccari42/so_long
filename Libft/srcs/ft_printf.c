/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzaccari <rzaccari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 14:58:28 by rzaccari          #+#    #+#             */
/*   Updated: 2023/01/23 02:55:37 by rzaccari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_printf(const char *input, ...)
{
	int		i;
	t_input	args;

	va_start(args.arguments, input);
	args.char_count = 0;
	i = 0;
	while (input[i] != '\0')
	{
		if (input[i] != '%')
			args.char_count += write(1, &input[i], 1);
		else
			format(&args, input[++i]);
		i++;
	}
	va_end(args.arguments);
	return (args.char_count);
}

void	format(t_input *args, char c)
{
	if (c == 'c')
		format_c(args);
	else if (c == 's')
		format_s(args);
	else if (c == 'p')
		format_p(args);
	else if (c == 'd')
		format_d(args);
	else if (c == 'i')
		format_i(args);
	else if (c == 'u')
		format_u(args);
	else if (c == 'x')
		format_x_lower(args);
	else if (c == 'X')
		format_x_upper(args);
	else if (c == '%')
		format_pc(args);
}

/*int main()
{
    unsigned int		nbr;
    int	n;
    int	n2;

    nbr = 4294967295; 
    n = ft_printf("%u", (unsigned int)4294967295);
    ft_printf("test : %u %%\n", nbr);
    n2 = printf("test : %u %%\n", nbr);
    printf("%i\n", n);
    printf("%i", n2);
}*/