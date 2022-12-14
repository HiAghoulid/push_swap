/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_min.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haghouli <haghouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 06:07:43 by haghouli          #+#    #+#             */
/*   Updated: 2022/12/10 11:41:54 by haghouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int find_min(t_stack *stack)
{
    int i;
    int min;
    int index;

    i = 0;
    index = 0;
    min = stack -> content;
    while (stack != NULL)
    {
        if (stack -> content < min)
        {
            min = stack -> content;
            index = i;
        }
        stack = stack -> next;
        i++;
    }
    return (index);
}