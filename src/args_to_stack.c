/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_to_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalcara- <aalcara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 18:59:29 by aalcara-          #+#    #+#             */
/*   Updated: 2021/07/18 20:25:50 by aalcara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static int	*reduce_numbers(int *numlist, t_stack *stack)
{
	int	i;
	int	j;
	int	count;
	int	*array;

	i = 0;
	j = 0;
	count = 0;
	array = (int *)malloc(sizeof(int) * (stack->len));
	while (i < stack->len)
	{
		while (j < stack->len)
		{
			if (numlist[j] < numlist[i])
				count++;
			j++;
		}
		array[i] = count;
		i++;
		j = 0;
		count = 0;
	}
	return (array);
}

static void	putargstostack_a(int *reduced, t_stack *stack)
{
	int		i;
	t_dlist *new;

	i = 0;
	while (i < stack->len)
	{
		new = ft_dlstnew(reduced[i]);
		ft_dlstadd_back(&(stack->a), new);
		i++;
	}
}

void	args_to_stack(int *numlist, t_stack *stack)
{
	int	*reduced;

	reduced = reduce_numbers(numlist, stack);
	putargstostack_a(reduced, stack);
	free(reduced);
	free(numlist);
}