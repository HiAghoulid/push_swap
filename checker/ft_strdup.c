/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haghouli <haghouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 21:34:24 by haghouli          #+#    #+#             */
/*   Updated: 2022/12/12 19:47:02 by haghouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./gnl/get_next_line.h"

char	*ft_strdup(const char *s1)
{
	size_t	size;
	size_t	i;
	char	*dup;

	i = 0;
	size = ft_strlen(s1);
	dup = (char *)malloc((size + 1) * sizeof(char));
	if (!dup)
		return (NULL);
	while (i < size)
	{
		dup[i] = s1[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
