/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_dup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haghouli <haghouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 09:21:40 by haghouli          #+#    #+#             */
/*   Updated: 2022/12/10 13:16:04 by haghouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int is_dup(t_stack *stack)
{
    t_stack *lst;

    while (stack != NULL)
    {
        lst = stack -> next;
        while (lst != NULL)
        {
            if (stack -> content == lst -> content)
                return (1);
            lst = lst -> next;
        }
        stack = stack -> next;
    }
    return (0);
}