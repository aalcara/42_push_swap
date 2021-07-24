/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalcara- <aalcara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 21:33:19 by aalcara-          #+#    #+#             */
/*   Updated: 2021/07/24 00:03:14 by aalcara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	return_to_a(t_stack *stack)
{
	while (ft_dlstlen(&stack->a) < stack->len)
	{
		push('a', stack);
		ft_printfstack (stack);
		if (stack->a->content > stack->a->next->content)
			rotate('a', stack);
	}
}

static void	threenum_sort(t_stack *stack)
{
	while (ft_dlstissorted(&stack->a) != 1)
	{
		if (stack->a->content > stack->a->next->content)
		{
			if (stack->a->next->content > stack->a->next->next->content)
				swap('a', stack);
			else if (stack->a->content > stack->a->next->next->content)
				rotate('a', stack);
			else
				swap('a', stack);
		}
		else if (stack->a->content > stack->a->next->next->content)
			reverse('a', stack);
		else
			swap('a', stack);
		ft_printfstack (stack);
	}
}

static void	short_sorter(t_stack *stack)
{
	int	small;
	int	big;

	small = 0;
	big = stack->len - 1;
	while (ft_dlstlen(&stack->a) > 3 && ft_dlstissorted(&stack->a) != 1)
	{
		if (stack->a->content == small || stack->a->content == big)
		{
			if (stack->a->content == small)
				small++;
			else
				big--;
			push('b', stack);	
		}
		else
			rotate('a', stack);
		ft_printfstack (stack);
	}
	threenum_sort(stack);
	return_to_a(stack);
	ft_printfstack (stack);//                                                     a
}

void	sorter(t_stack *stack)
{
	ft_printfstack (stack);//                                                     a
	if (stack->len == 2)
	{
		if (ft_dlstissorted(&stack->a) == 0)
			swap('a', stack);
		free_exit(stack);
	}
	if (stack->len <= 5)
		short_sorter(stack);
	else
		long_sorter(stack);
}