/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_shunkes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haghouli <haghouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 06:47:57 by haghouli          #+#    #+#             */
/*   Updated: 2022/12/22 11:00:04 by haghouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	push_shunckes(t_stack **stack_a, t_stack **stack_b, int div)
{
	int shunk_size;
	int shunk_index;
	int count;

	shunk_index = 1;
	count = 1;
	shunk_size = (ft_lstsize(*stack_a) / div);
	while (*stack_a)
	{
		if ((*stack_a)->index < shunk_size * shunk_index)
		{
			push_b(stack_a, stack_b);
			if ((*stack_b)->index < (shunk_index * shunk_size) - (shunk_size / 2))
				rotate_b(stack_b);
			count++;
		}
		else
		{
			while ((*stack_a)->index >= shunk_size * shunk_index)
				rotate_a(stack_a);
		}
		if (count == shunk_size * shunk_index)
			shunk_index++;
	}
}