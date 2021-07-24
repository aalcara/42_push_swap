/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalcara- <aalcara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 21:38:58 by aalcara-          #+#    #+#             */
/*   Updated: 2021/07/24 00:09:35 by aalcara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	ft_dlstissorted(t_dlist **dlist)
{
	t_dlist	*aux;

	aux = *dlist;
	while (aux->next != NULL)
	{
		if (aux->content > aux->next->content)
			return (0);
		else
			aux = aux->next;
	}
	return (1);
}

int	ft_dlstlen(t_dlist **dlist)
{
	t_dlist *aux;
	int		count;

	count = 0;
	aux = *dlist;
	while (aux != NULL)
	{
		count++;
		aux = aux->next;
	}
	return (count);
}