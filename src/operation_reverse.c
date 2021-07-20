/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_reverse.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalcara- <aalcara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 17:35:04 by aalcara-          #+#    #+#             */
/*   Updated: 2021/07/19 19:33:46 by aalcara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	reverse_stack(t_dlist **stack)
{
	t_dlist *first;
	t_dlist *last;

	if (*stack == NULL)
		return ;
	first = *stack;
	if (first->next == NULL)
		return ;
	last = ft_dlstlast(*stack);
	last->prev->next = NULL;
	last->next = first;
	last->prev = NULL;
	first->prev = last;
	*stack = last;
}

void	reverse(char stack_name, t_stack *stack)
{
	if (stack_name == 'a')
	{
		reverse_stack(&stack->a);
		ft_putstr("rra\n");
	}
	else if (stack_name == 'b')
	{
		reverse_stack(&stack->b);
		ft_putstr("rrb\n");
	}
	else if (stack_name == 'r')
	{
		reverse_stack(&stack->a);
		reverse_stack(&stack->b);
		ft_putstr("rrr\n");
	}
	else
		ft_putstr("Error on stack name of reverse operation\n");
}