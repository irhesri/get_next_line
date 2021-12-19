/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhesri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 08:05:47 by irhesri           #+#    #+#             */
/*   Updated: 2021/12/18 08:06:42 by irhesri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*read_next_line(char *str, int fd)
{
	char	*s;
	ssize_t	len;
	int		size;

	size = 0;
	s = NULL;
	s = ft_endlsplit(s, str, &size);
	if (s[size - 1] == '\n')
		return (s);
	len = 1;
	while (len > 0)
	{
		len = read(fd, str, BUFFER_SIZE);
		if (len > 0)
		{
			str[len] = '\0';
			s = ft_endlsplit(s, str, &size);
			if (s[size - 1] == '\n')
				return (s);
		}
	}
	return (s);
}

char	*get_next_line(int fd)
{
	static char	*str[OPEN_MAX];
	char		*s;

	if (fd < 0 || (BUFFER_SIZE <= 0) || fd > OPEN_MAX)
		return (NULL);
	if (!str[fd])
	{
		str[fd] = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!str[fd])
			return (NULL);
		str[fd][0] = '\0';
	}
	s = read_next_line(str[fd], fd);
	if (*s == '\0')
	{
		free (str[fd]);
		free (s);
		str[fd] = NULL;
		return (NULL);
	}
	return (s);
}
