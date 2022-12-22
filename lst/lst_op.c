/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haghouli <haghouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 05:40:06 by haghouli          #+#    #+#             */
/*   Updated: 2022/12/11 08:03:37 by haghouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*t;

	if (new == NULL || lst == NULL)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		t = *lst;
		while (t->next != NULL)
			t = t->next;
		t->next = new;
	}
}

void	ft_lstadd_front(t_stack **lst, t_stack *new)
{
	if (new == 0)
		return ;
	new->next = *lst;
	*lst = new;
}

t_stack	*ft_lstlast(t_stack *lst)
{
	t_stack	*t;

	if (lst == NULL)
		return (NULL);
	t = lst;
	while (t->next != NULL)
		t = t->next;
	return (t);
}

t_stack	*ft_lstnew(int content)
{
	t_stack	*head;

	head = (t_stack *)malloc(sizeof(t_stack));
	if (!head)
		return (NULL);
	head->content = content;
	head->index = 0;
	head->next = NULL;
	return (head);
}

int	ft_lstsize(t_stack *lst)
{
	int i;

	i = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}