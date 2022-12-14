/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haghouli <haghouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 07:55:26 by haghouli          #+#    #+#             */
/*   Updated: 2022/12/11 08:53:55 by haghouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"


void    index_lst(t_stack *stack)
{
    int i;
    t_stack *tmp;
    int size;

    i = 0;
    tmp = stack;
    size = ft_lstsize(tmp);
    int *lst = ft_cpy_and_get_middle(stack);
    while (i < size)
    {
        tmp = stack;
        while (tmp != NULL)
        {
            if (lst[i] == tmp -> content)
                tmp -> index = i + 1;
            tmp = tmp -> next;
        }
        i++;
    }
}