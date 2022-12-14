/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haghouli <haghouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 13:09:41 by haghouli          #+#    #+#             */
/*   Updated: 2022/12/06 10:27:43 by haghouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

static int	ft_isdigit(char c)
{
	if(c >= '0' && c <= '9')
		return (1);
	return (0);
}

static int	is_space(char c)
{
	if (((c >= 9) && (c <= 13)) || (c == ' '))
		return (1);
	return (0);
}

long	ft_atoi(const char *str)
{
	unsigned long	num;
	unsigned long	sign;

	num = 0;
	sign = 1;
	while (*str && (is_space(*str) == 1))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while ((ft_isdigit(*str) == 1) && *str)
	{
		num = num * 10 + *str - '0';
		str++;
	}
	return (num * sign);
}