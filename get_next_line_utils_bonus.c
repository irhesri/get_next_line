/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhesri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 08:07:08 by irhesri           #+#    #+#             */
/*   Updated: 2021/12/18 08:08:24 by irhesri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static	int	ft_strcopy(char *s1, char *s2, char c)
{
	int	i;

	i = 0;
	while (s2[i] && (s2[i] != c))
	{
		s1[i] = s2[i];
		i++;
	}
	if (c == '\n' && (s2[i] == '\n'))
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
	return (i);
}

char	*ft_endlsplit(char *s1, char *s2, int *size)
{
	int		size1;
	int		i;
	char	*str;

	size1 = (*size) + BUFFER_SIZE + 1;
	i = 0;
	str = (char *) malloc(sizeof(char) * size1);
	if (!str)
		return (NULL);
	if (s1 && *s1)
		i = ft_strcopy(str, s1, '\0');
	(*size) = i;
	i = ft_strcopy(&str[i], s2, '\n');
	(*size) += i;
	ft_strcopy(s2, &s2[i], '\0');
	free (s1);
	return (str);
}
