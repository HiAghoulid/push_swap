/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lfive_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haghouli <haghouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 08:03:53 by haghouli          #+#    #+#             */
/*   Updated: 2022/12/22 08:57:36 by haghouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

static void	insertion_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	j;
	int	i;
	int	size;

	j = 0;
	while (j < 2)
	{
		size = ft_lstsize(*stack_a);
		i = find_min(*stack_a);
		if (i > size / 2)
		{
			while (i < size)
			{
				reverse_rotate_a(stack_a);
				i++;
			}
		}
		else
		{
			while (i > 0)
			{
				rotate_a(stack_a);
				i--;
			}
		}
		push_b(stack_a, stack_b);
		j++;
	}
}

void	lfive_sort(t_stack **stack_a, t_stack **stack_b)
{
	insertion_sort(stack_a, stack_b);
	lthree_sort(stack_a);
	if (is_sorted(*stack_b))
		swap_b(stack_b);
	push_a(stack_a, stack_b);
	push_a(stack_a, stack_b);
}