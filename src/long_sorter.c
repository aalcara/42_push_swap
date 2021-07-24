/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_sorter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalcara- <aalcara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 00:05:33 by aalcara-          #+#    #+#             */
/*   Updated: 2021/07/24 19:05:30 by aalcara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	push_zeros_to_b(t_stack *stack)
{
	static int	bits = 0;
	int			i;

	i = 0;
	while (i < stack->len)
	{
		if (((stack->a->content >> bits) & 1) == 1)
			rotate('a', stack);
		else
			push('b', stack);
		i++;
	}
	bits++;
}

void	long_sorter(t_stack *stack)
{
	while (ft_dlstissorted(&stack->a) != 1)
	{
		push_zeros_to_b(stack);
		while (stack->b != NULL)
			push('a', stack);
	}
}
