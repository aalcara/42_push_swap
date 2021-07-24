/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalcara- <aalcara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 10:04:01 by aalcara-          #+#    #+#             */
/*   Updated: 2021/07/24 19:00:10 by aalcara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <limits.h>

typedef struct s_stack
{
	t_dlist	*a;
	t_dlist	*b;
	int		len;
}	t_stack;

void	error_exit(void);
void	free_exit(t_stack *stack);
int		*verify_args(int argc, char **argv);
void	args_to_stack(int *numlist, t_stack *stack);
void	sorter(t_stack *stack);
void	long_sorter(t_stack *stack);
/*
** Operations
*/
void	swap(char stack_name, t_stack *stack);
void	push(char stack_name, t_stack *stack);
void	rotate(char stack_name, t_stack *stack);
void	reverse(char stack_name, t_stack *stack);

#endif