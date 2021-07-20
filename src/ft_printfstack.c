#include "../inc/push_swap.h"
#include <stdio.h> //                                                             a

void	ft_printfstack(t_stack *stack)
{
	int i = 1;
	t_dlist *aux;
	t_dlist *auxb;

	aux = stack->a;
	auxb = stack->b;
	printf("i\ta\tb");
	while (i <= stack->len)
	{
		printf("\n%d\t", i);
		if (aux != NULL)
		{
			printf("%d\t", aux->content);
			aux = aux->next;
		}
		else
			printf("-\t");
		if (auxb != NULL)
		{
			printf("%d\t", auxb->content);
			auxb = auxb->next;
		}
		else
			printf("-\t");
		i++;
	}
	printf("\n-------------------\n");
}
