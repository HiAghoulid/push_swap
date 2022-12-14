/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haghouli <haghouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 13:00:05 by haghouli          #+#    #+#             */
/*   Updated: 2022/12/12 20:00:16 by haghouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./gnl/get_next_line.h"
#include "../header/push_swap.h"
#include <string.h>


int main(int ac, char *av[])
{
    t_stack *stack_a;
    t_stack *stack_b;

    stack_a = NULL;
    stack_b = NULL;
    t_stack *tmp;
    int i = 0;
    if (ac > 1)
    {
        if(!fill_stack(&stack_a, av, ac) || is_error(stack_a))
            return (0);
    }
    char *str;
    // while (1)
    // {
    //     str = get_next_line(0);
    //     if(!str)
    //         break;
    // }
    while (1)
    {
        str = get_next_line(0);
        if(!str)
            break;
        if(!strcmp("sa\n",str))
            swap(&stack_a);
        if(!strcmp("sb\n",str))
            swap(&stack_b);
        if(!strcmp("pa\n",str))
            push(&stack_a, &stack_b);
        if(!strcmp("pb\n",str))
            push(&stack_b, &stack_a);
        if(!strcmp("ra\n",str))
            rotate(&stack_a);
        if(!strcmp("rb\n",str))
            rotate(&stack_b);
        if(!strcmp("rra\n",str))
            reverse_rotate(&stack_a);
        if(!strcmp("rrb\n",str))
            reverse_rotate(&stack_b);
        if(!strcmp("rr\n",str))
            rotate_ab(&stack_a, &stack_b);
        if(!strcmp("rrr\n",str))
            reverse_rotate_ab(&stack_a, &stack_b);
    }
    if(is_sorted(stack_a) && stack_b == NULL)
        ft_putstr("OK\n");
    else
        ft_putstr("KO\n");
    return(0);
}