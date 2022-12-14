/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lthree_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haghouli <haghouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 06:07:51 by haghouli          #+#    #+#             */
/*   Updated: 2022/12/10 13:29:42 by haghouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void    lthree_sort_a(t_stack **stack)
{
    int max_index;
    int min_index;

    if(is_sorted(*stack))
        return ;
    max_index = find_max(*stack);
    min_index = find_min(*stack);
    if (is_sorted_dec(*stack))
    {
        swap_a(stack);
        reverse_rotate_a(stack);
    }
    else if (max_index == 0)
        rotate_a(stack);
    else if (max_index == ft_lstsize(*stack) - 1)
        swap_a(stack);
    else if (min_index == 0)
    {
        swap_a(stack);
        rotate_a(stack);
    }
    else if (min_index == ft_lstsize(*stack) - 1)
        reverse_rotate_a(stack);
}

void    lthree_sort_b(t_stack **stack)
{
    int max_index;
    int min_index;

    if(is_sorted(*stack))
        return ;
    max_index = find_max(*stack);
    min_index = find_min(*stack);
    if (is_sorted_dec(*stack))
    {
        swap_b(stack);
        reverse_rotate_b(stack);
    }
    else if (max_index == 0)
        rotate_b(stack);
    else if (max_index == ft_lstsize(*stack) - 1)
        swap_b(stack);
    else if (min_index == 0)
    {
        swap_b(stack);
        rotate_b(stack);
    }
    else if (min_index == ft_lstsize(*stack))
        reverse_rotate_b(stack);
}

void    lthree_sort(t_stack **stack_a, t_stack **stack_b,char c)
{
    if(c == 'a')
        lthree_sort_a(stack_a);
    else
        lthree_sort_b(stack_b);
}