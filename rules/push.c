/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haghouli <haghouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 10:38:52 by haghouli          #+#    #+#             */
/*   Updated: 2022/12/12 16:52:10 by haghouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void    push(t_stack **stack_a,t_stack **stack_b)
{
    t_stack *tmp;
    if(*stack_b == NULL)
        return ;
    tmp = (*stack_b) -> next;
    ft_lstadd_front(stack_a, *stack_b);
    *stack_b = tmp;  
}

void    push_a(t_stack  **stack_a, t_stack **stack_b)
{
    push(stack_a, stack_b);
    ft_putstr("pa\n");
}

void    push_b(t_stack **stack_a, t_stack **stack_b)
{
    push(stack_b, stack_a);
    ft_putstr("pb\n");
}



