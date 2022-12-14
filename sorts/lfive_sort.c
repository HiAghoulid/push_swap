/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lfive_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haghouli <haghouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 08:03:53 by haghouli          #+#    #+#             */
/*   Updated: 2022/12/09 16:14:54 by haghouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void    lfive_sort(t_stack *e)
{
    push_b(e);
    push_b(e);

    lthree_sort(e, 'a');
    
    if((e -> stack_b[e -> len2] < e -> stack_a[0]) && (e -> stack_b[0] < e -> stack_a[0]))
    {
        push_a(e);
        push_a(e);
        if(is_sorted(e ->stack_b, e -> len2))
            swap_b(e);
        reverse_rotate_a(e);
        reverse_rotate_a(e);
    }
}