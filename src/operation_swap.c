/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalcara- <aalcara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 20:41:22 by aalcara-          #+#    #+#             */
/*   Updated: 2021/07/24 19:05:47 by aalcara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	swap_stack(t_dlist **stack_name)
{
	t_dlist	*first;
	t_dlist	*second;

	if (*stack_name == NULL)
		return ;
	first = *stack_name;
	second = first->next;
	if (second == NULL)
		return ;
	first->next = second->next;
	first->prev = second;
	if (second->next)
		second->next->prev = first;
	second->next = first;
	second->prev = NULL;
	*stack_name = second;
}

void	swap(char stack_name, t_stack *stack)
{
	if (stack_name == 'a')
	{
		swap_stack(&stack->a);
		ft_putstr("sa\n");
	}
	else if (stack_name == 'b')
	{
		swap_stack(&stack->b);
		ft_putstr("sb\n");
	}
	else if (stack_name == 's')
	{
		swap_stack(&stack->a);
		swap_stack(&stack->b);
		ft_putstr("ss\n");
	}
	else
		ft_putstr("Error on stack name of swap operation\n");
}
