/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haghouli <haghouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 10:35:04 by haghouli          #+#    #+#             */
/*   Updated: 2022/12/12 16:44:48 by haghouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void swap(t_stack **stack)
{
    t_stack *tmp;
    t_stack *lst;

    tmp = *stack;
    lst = (*stack) -> next;
    tmp -> next = lst -> next;
    lst -> next = tmp;
    *stack = lst;   
}

void    swap_a(t_stack **stack)
{
    swap(stack);
    ft_putstr("sa\n");
}

void    swap_b(t_stack **stack)
{
    swap(stack);
    ft_putstr("sb\n");
}

void swap_ab(t_stack **stack)
{
    swap(stack);                    
    swap(stack);
    ft_putstr("ss\n");
}