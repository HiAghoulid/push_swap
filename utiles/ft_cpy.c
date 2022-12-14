/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haghouli <haghouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 13:15:44 by haghouli          #+#    #+#             */
/*   Updated: 2022/12/11 08:45:19 by haghouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int   *ft_cpy_and_get_middle(t_stack *stack)
{
    int i = 0;
    int *list;
    int size;
    
    size = ft_lstsize(stack);
    list = malloc(size * sizeof(int));
    while (i < size)
    {
        list[i++] = stack -> content;
        stack = stack -> next;
    }
    sort(list, size);
    return (list);
}