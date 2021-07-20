/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalcara- <aalcara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 08:32:13 by aalcara-          #+#    #+#             */
/*   Updated: 2021/07/19 17:22:27 by aalcara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	push_stack(t_dlist **origin_stack, t_dlist **dest_stack)
{
	t_dlist	*orig;
	t_dlist	*dest;

	orig = *origin_stack;
	dest = *dest_stack;
	if (orig->next == NULL)
		*origin_stack = NULL;
	else
	{
		*origin_stack = orig->next;
		orig->next->prev = NULL;
	}
	if (dest != NULL)
	{
		dest->prev = orig;
		orig->next = dest;
		*dest_stack = dest->prev;
		return ;
	}
	orig->next = NULL;
	orig->prev = NULL;
	*dest_stack = orig;
}

static void	put_push(char stack_name)
{
	ft_putchar('p');
	ft_putchar(stack_name);
	ft_putchar('\n');
}

void	push(char stack_name, t_stack *stack)
{
	if (stack_name == 'a')
	{
		push_stack(&stack->b, &stack->a);
		if (stack->b == NULL)
			ft_putstr("trying to push from NULL!");
		// orig = stack->b;
		// dest = stack->a;
	}
	else if (stack_name == 'b')
	{
		push_stack(&stack->a, &stack->b);
		if (stack->a == NULL)
			ft_putstr("trying to push from NULL!");
		// orig = stack->a;
		// dest = stack->b;
	}
	else
		ft_putstr("Unknown stack name");
	put_push(stack_name);
}