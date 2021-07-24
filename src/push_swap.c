/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalcara- <aalcara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 09:24:12 by aalcara-          #+#    #+#             */
/*   Updated: 2021/07/24 19:06:14 by aalcara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	init_stacks(t_stack *stack, int argc)
{
	stack->a = NULL;
	stack->b = NULL;
	stack->len = argc - 1;
}

int	main(int argc, char **argv)
{
	t_stack	stack;
	int		*numlist;

	numlist = verify_args(argc, argv);
	init_stacks(&stack, argc);
	args_to_stack(numlist, &stack);
	sorter(&stack);
	free_exit(&stack);
	return (1);
}
