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

#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1000
#endif

static char	*ft_endlsplit(char *s1, char *s2, int *size)
{
	int		i;
	int		j;
	char	*str;

	i = -1;
	str = (char *) malloc(sizeof(char) * (*size + BUFFER_SIZE + 1));
	if (!str)
		return (NULL);
	while (s1 && *s1 && s1[++i])
		str[i] = s1[i];
	while (s2 && s2[++i] && s2[i] != '\n')
		str[i] = s2[i];
	str[i] = s2[i];
	if (str[i])
		str[++i] = '\0';
	(*size) = i;
	j = -1;
	while (s2[i])
		s2[++j] = s2[i++];
	s2[++j] = s2[i];
	free (s1);
	return (str);
}

static char	*read_next_line(char *str, int fd)
{
	char	*s;
	ssize_t	len;
	int		size;

	size = 0;
	s = ft_endlsplit(NULL, str, &size);
	if (s[size - 1] == '\n')
		return (s);
	len = read(fd, str, BUFFER_SIZE);
	while (len > 0)
	{
		str[len] = '\0';
		s = ft_endlsplit(s, str, &size);
		if (s[size - 1] == '\n')
			return (s);
		len = read(fd, str, BUFFER_SIZE);
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
	if (!s || *s == '\0')
	{
		free (str[fd]);
		if (s)
			free (s);
		str[fd] = NULL;
		return (NULL);
	}
	return (s);
}
