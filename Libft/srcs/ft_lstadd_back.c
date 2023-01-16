/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzaccari <rzaccari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 17:01:11 by rzaccari          #+#    #+#             */
/*   Updated: 2023/01/16 15:44:17 by rzaccari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*current;

	if (*alst == NULL)
	{
		*alst = new;
		return ;
	}
	current = *alst;
	while (current->next != NULL)
		current = current->next;
	current->next = new;
}
