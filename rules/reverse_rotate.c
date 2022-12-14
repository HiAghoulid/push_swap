/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haghouli <haghouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 11:14:26 by haghouli          #+#    #+#             */
/*   Updated: 2022/12/12 16:42:05 by haghouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void reverse_rotate(t_stack **stack)
{
    t_stack *tmp;
    t_stack *lst;
    if(ft_lstsize(*stack) == 1)
        return ;

    lst = *stack;
    tmp = ft_lstlast(*stack);
    while (lst -> next -> next != NULL)
        lst = lst -> next;
    lst -> next = NULL;
    ft_lstadd_front(stack, tmp);
}

void    reverse_rotate_a(t_stack **stack)
{
    reverse_rotate(stack);
    ft_putstr("rra\n");
}

void    reverse_rotate_b(t_stack **stack)
{
    reverse_rotate(stack);
    ft_putstr("rrb\n");
}

void    reverse_rotate_ab(t_stack **stack_a, t_stack **stack_b)
{
    reverse_rotate(stack_a);
    reverse_rotate(stack_b);
    ft_putstr("rrr\n");
}
