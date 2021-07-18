/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalcara- <aalcara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 09:24:12 by aalcara-          #+#    #+#             */
/*   Updated: 2021/07/17 23:22:01 by aalcara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include <stdio.h>

int	*reduce_numbers(int argc, int *numlist)
{
	int	i;
	int	j;
	int	count;
	int	*array;

	i = 0;
	j = 0;
	count = 0;
	array = (int *)malloc(sizeof(int) * (argc - 1));
	while (i < argc - 1)
	{
		while (j < argc - 1)
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

void	args_to_stack(int argc, int *numlist)//, t_stack *stack)
{
	int	*reduced;

	reduced = reduce_numbers(argc, numlist);
	

	int i = 0;
	while (i < argc - 1)
	{
		printf("i = %d,\tnbr = %d,\treduced = %d\n", i, numlist[i], reduced[i]);
		i++;;
	}
	//free(reduced);
	//free(numlist);
}

int	main(int argc, char **argv)
{
	// t_stack	stack;
	int	*numlist;
	
	numlist = verify_args(argc, argv);
	args_to_stack(argc, numlist);//), &stack);
	return (1);
}
