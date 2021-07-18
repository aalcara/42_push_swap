/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalcara- <aalcara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 20:43:16 by aalcara-          #+#    #+#             */
/*   Updated: 2021/07/17 22:18:11 by aalcara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

typedef struct s_dlist
{
	int				content;
	struct s_dlist	*next;
	struct s_dlist	*prev;
}	t_dlist;

t_dlist	*ft_dlstnew(int content)
{
	t_dlist *newpointer;

	newpointer = (t_dlist *)malloc(sizeof(t_dlist));
	if (!(newpointer))
		return (NULL);
	newpointer->content = content;
	newpointer->next = NULL;
	newpointer->prev = NULL;
	return (newpointer);
}

t_dlist *ft_dlstlast(t_dlist *list)
{
	t_dlist	*aux;

	if (list == NULL)
		return (list);
	aux = list;
	while (aux->next != NULL)
		aux = aux->next;
	return (aux);
}

void	ft_dlstadd_back(t_dlist **list, t_dlist *new)
{
	t_dlist	*aux;

	if (new == NULL)
		return ;
	if (*list == NULL)
	{
		*list = new;
		return ;
	}
	aux = ft_dlstlast(*list);
	aux->next = new;
	new->prev = aux;
}

void	ft_dlstadd_front(t_dlist **list, t_dlist *new)
{
	t_dlist *aux;

	if (new == NULL)
		return ;
	aux = *list;
	*list = new;
	new->next = aux;
	aux->prev = new;
}

int	main(void)
{
	int	i = 0;
	t_dlist *list;
	t_dlist	*new;
	t_dlist *aux;

	while (i++ < 10)
	{
		new = ft_dlstnew(i);
		ft_dlstadd_back(&list, new);
	}
	new = ft_dlstnew(1995);
	ft_dlstadd_back(&list, new);
	new = ft_dlstnew(99);
	ft_dlstadd_front(&list, new);
	aux = list;
	i = 0;
	while (aux->next != NULL)
	{
		printf("i = %d, content = %d, ", i, aux->content);
		if (aux->next)
			printf("next = %d, ", aux->next->content);
		else
			printf("next = NULL, ");
		if (aux->prev)
			printf("prev = %d\n", aux->prev->content);
		else
			printf("prev = NULL\n");
		i++;
		aux = aux->next;
	}
	printf("i = %d, content = %d, ", i, aux->content);
	if (aux->next)
		printf("next = %d, ", aux->next->content);
	else
		printf("next = NULL, ");
	if (aux->prev)
		printf("prev = %d\n", aux->prev->content);
	else
		printf("prev = NULL\n");
	return 0;
}
