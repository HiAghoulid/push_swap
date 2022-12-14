/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haghouli <haghouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 13:16:28 by haghouli          #+#    #+#             */
/*   Updated: 2022/12/11 08:46:19 by haghouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

static void ft_swap(int *a, int *b)
{
    int tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}

void sort(int *list, int len)
{
    int i = 0;
    int j = 0;

    while(i < len)
    {
        j = i + 1;
        while(j < len)
        {
            if(list[i] > list[j])
                ft_swap(&list[i], &list[j]);
            j++;
        }
        i++;
    }
}