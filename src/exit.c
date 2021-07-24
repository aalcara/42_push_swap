/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalcara- <aalcara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 13:48:34 by aalcara-          #+#    #+#             */
/*   Updated: 2021/07/24 19:03:35 by aalcara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	error_exit(void)
{
	ft_putstr("Error\n");
	exit(0);
}

void	free_exit(t_stack *stack)
{
	ft_dlstclear(&stack->a);
	ft_dlstclear(&stack->b);
	exit(0);
}
