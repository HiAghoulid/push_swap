/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haghouli <haghouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 13:22:52 by haghouli          #+#    #+#             */
/*   Updated: 2022/12/10 12:52:50 by haghouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	fill_stack(t_stack **stack, char **av, int ac)
{
	int i;
	i = 0;

	while (i < (ac - 1))
	{
		ft_lstadd_back(stack, ft_lstnew(ft_atoi(av[i + 1])));
		if ((ft_atoi(av[i + 1]) > INT_MAX) || !is_int(av[i + 1]))
		{
			ft_putstr("Error\n");
			return (0);
		}
		i++;
	}
	return (1);
}