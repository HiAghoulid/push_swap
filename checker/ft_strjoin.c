/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haghouli <haghouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 08:11:11 by haghouli          #+#    #+#             */
/*   Updated: 2022/12/12 19:45:46 by haghouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./gnl/get_next_line.h"

static char	*combine(const char *s1, const char *s2)
{
	int		i;
	int		j;
	char	*joined_str;
	int		full_size;

	i = 0;
	j = 0;
	full_size = (ft_strlen(s1) + ft_strlen(s2));
	joined_str = (char *)malloc((full_size + 1) * sizeof(char));
	if (!joined_str)
		return (0);
	while (i < full_size)
	{
		while (s1[j])
			joined_str[i++] = s1[j++];
		j = 0;
		while (s2[j])
			joined_str[i++] = s2[j++];
	}
	joined_str[i] = '\0';
	return (joined_str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	if (s1 == 0 && s2 == 0)
		return (NULL);
	if (s1 == 0)
		return (ft_strdup(s2));
	if (s2 == 0)
		return (ft_strdup(s1));
	return (combine(s1, s2));
}
