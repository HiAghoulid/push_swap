/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_max.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haghouli <haghouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 19:19:26 by haghouli          #+#    #+#             */
/*   Updated: 2022/12/20 07:57:58 by haghouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	find_max(t_stack *stack)
{
	int	i;
	int	max;
	int	index;

	i = 0;
	index = 0;
	max = stack->content;
	while (stack != NULL)
	{
		if (stack->content > max)
		{
			max = stack->content;
			index = i;
		}
		stack = stack->next;
		i++;
	}
	return (index);
}
