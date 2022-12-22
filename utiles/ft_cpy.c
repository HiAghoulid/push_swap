/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haghouli <haghouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 13:15:44 by haghouli          #+#    #+#             */
/*   Updated: 2022/12/22 11:15:05 by haghouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int *cpy_to_array(t_stack *stack)
{
    int i;
	int size;

	i = 0;
	size = ft_lstsize(stack);
    int *arr = malloc(size * sizeof(int));
    while (stack)
    {
        arr[i++] = stack->content;
        stack = stack -> next;
    }
	sort(arr, ft_lstsize(stack));
    return (arr);
}