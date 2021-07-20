/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalcara- <aalcara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 09:24:12 by aalcara-          #+#    #+#             */
/*   Updated: 2021/07/19 19:33:41 by aalcara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
void	ft_printfstack(t_stack *stack);

void	init_stacks(t_stack *stack, int argc)
{
	stack->a = NULL;
	stack->b = NULL;
	stack->len = argc - 1;
}

void	free_exit(t_stack *stack)
{
	ft_dlstclear(&stack->a);
	ft_dlstclear(&stack->b);
	exit(0);
}

int	main(int argc, char **argv)
{
	t_stack	stack;
	int	*numlist;
	
	numlist = verify_args(argc, argv);
	init_stacks(&stack, argc);
	args_to_stack(numlist, &stack);




	ft_printfstack (&stack);
	swap('a', &stack);
	ft_printfstack (&stack);
	push('b', &stack);
	ft_printfstack (&stack);
	push('b', &stack);
	ft_printfstack (&stack);
	swap('s', &stack);
	ft_printfstack (&stack);
	rotate('a', &stack);
	ft_printfstack (&stack);
	push('b', &stack);
	ft_printfstack (&stack);
	push('b', &stack);
	ft_printfstack (&stack);
	rotate('b', &stack);
	ft_printfstack (&stack);
	rotate('r', &stack);
	ft_printfstack (&stack);
	reverse('a', &stack);
	ft_printfstack (&stack);
	reverse('b', &stack);
	ft_printfstack (&stack);
	reverse('r', &stack);
	ft_printfstack (&stack);

	
	free_exit(&stack);
	return (1);
}
