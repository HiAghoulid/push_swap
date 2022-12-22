/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haghouli <haghouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 13:21:45 by haghouli          #+#    #+#             */
/*   Updated: 2022/12/10 06:17:33 by haghouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	is_error(t_stack *stack)
{
	if (is_dup(stack))
	{
		ft_putstr("Error\n");
		return (1);
	}
	if (is_sorted(stack))
		return (1);
	return (0);
}