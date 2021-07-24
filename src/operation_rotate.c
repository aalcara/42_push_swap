/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalcara- <aalcara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 17:35:04 by aalcara-          #+#    #+#             */
/*   Updated: 2021/07/24 19:03:30 by aalcara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	rotate_stack(t_dlist **stack)
{
	t_dlist	*first;
	t_dlist	*second;
	t_dlist	*last;

	if (*stack == NULL)
		return ;
	first = *stack;
	if (first->next == NULL)
		return ;
	second = first->next;
	last = ft_dlstlast(*stack);
	first->next = NULL;
	first->prev = last;
	last->next = first;
	second->prev = NULL;
	*stack = second;
}

void	rotate(char stack_name, t_stack *stack)
{
	if (stack_name == 'a')
	{
		rotate_stack(&stack->a);
		ft_putstr("ra\n");
	}
	else if (stack_name == 'b')
	{
		rotate_stack(&stack->b);
		ft_putstr("rb\n");
	}
	else if (stack_name == 'r')
	{
		rotate_stack(&stack->a);
		rotate_stack(&stack->b);
		ft_putstr("rr\n");
	}
	else
		ft_putstr("Error on stack name of rotate operation\n");
}
