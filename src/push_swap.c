/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalcara- <aalcara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 09:24:12 by aalcara-          #+#    #+#             */
/*   Updated: 2021/07/18 22:09:48 by aalcara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include <stdio.h> //                                                             a

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

	//erase
	t_dlist *aux;
	int i = 0;
	ft_swap('a', &stack);

	
	aux = stack.a;
	while (i < stack.len && aux != NULL)
	{
		printf("i = %d\tstack_a = %d\n", i, aux->content);
		i++;
		aux = aux->next;
	}

	
	free_exit(&stack);
	return (1);
}
