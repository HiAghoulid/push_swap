/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haghouli <haghouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 09:50:45 by haghouli          #+#    #+#             */
/*   Updated: 2022/12/12 16:43:25 by haghouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"


void    rotate(t_stack **stack)
{
    t_stack *tmp;

    if(ft_lstsize(*stack) == 1)
        return ;
    tmp = *stack;
    (*stack) = (*stack) -> next;
    tmp -> next = NULL;
    ft_lstadd_back(stack, tmp);
}

void    rotate_a(t_stack **stack)
{
    rotate(stack);
    ft_putstr("ra\n");
}


void    rotate_b(t_stack **stack)
{
    rotate(stack);
    ft_putstr("rb\n");
}

void    rotate_ab(t_stack **stack_a, t_stack **stack_b)
{
    rotate(stack_a);
    rotate(stack_b);
    ft_putstr("rr\n");
}
