/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhesri <irhesri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 08:05:47 by irhesri           #+#    #+#             */
/*   Updated: 2022/07/01 23:36:08 by irhesri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*join(char *str1, char *str2, int *len)
{
	char	*s;
	int		i;
	int		j;

	i = 0;
	s = malloc(*len);
	(*len) = 0;
	while (str1 && str1[i])
		s[(*len)++] = str1[i++];
	if (str1)
		free(str1);
	i = 0;
	while (str2[i] && (i == 0 || str2[i - 1] != '\n'))
		s[(*len)++] = str2[i++];
	if ((*len) == 0)
	{
		free (s);
		return (NULL);
	}
	s[(*len)] = '\0';
	j = 0;
	while (str2[i - 1])
		str2[j++] = str2[i++];
	return (s);
}

char	*read_next_line(int fd, char *str)
{
	int		n;
	int		len;
	char	*s;

	s = NULL;
	len = BUFFER_SIZE + 1;
	while (1)
	{
		if (*str)
		{
			s = join(s, str, &len);
			if (len > 0 && s[len - 1] == '\n')
				return (s);
		}
		n = read(fd, str, BUFFER_SIZE);
		if (!n)
			return (s);
		if (n < 0)
			return (NULL);
		str[n] = '\0';
		len += (n + 1);
	}
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
	s = read_next_line(fd, str[fd]);
	if (!str[fd][0])
	{
		free (str[fd]);
		str[fd] = NULL;
	}
	return (s);
}

// int	main()
// {
// 	int		fd1 = open("get_next_line_bonus.h", O_RDONLY);
// 	int		fd2 = open("get_next_line.h", O_RDONLY);
// 	char	*str1;
// 	char	*str2;

// 	str1 = get_next_line(fd1);
// 	str2 = get_next_line(fd2);
// 	while (str1 || str2)
// 	{
// 		printf("%s", str1);
// 		if (str1);
// 			free (str1);
// 		str1 = get_next_line(fd1);
// 		printf("%s", str2);
// 		if (str2)
// 			free (str2);
// 		str2 = get_next_line(fd2);
// 	}
// }