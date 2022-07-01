/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhesri <irhesri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 08:11:49 by irhesri           #+#    #+#             */
/*   Updated: 2022/07/01 23:35:25 by irhesri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
		// {
		// 	free (s);
			return (NULL);
		// }
		str[n] = '\0';
		len += (n + 1);
	}
}

char	*get_next_line(int fd)
{
	static char	*str = NULL;
	char		*s;

	if (fd < 0 || (BUFFER_SIZE <= 0) || fd > OPEN_MAX)
		return (NULL);
	if (!str)
	{
		str = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!str)
			return (NULL);
		str[0] = '\0';
	}
	s = read_next_line(fd, str);
	if (!*str)
	{
		free (str);
		str = NULL;
	}
	return (s);
}

// int	main()
// {
// 	int		fd = open("get_next_line_bonus.h", O_RDONLY);
// 	char	*str;

// 	str = get_next_line(fd);
// 	while (str)
// 	{
// 		printf("%s", str);
// 		free (str);
// 		str = get_next_line(fd);
// 	}
// // check for null
// 	printf("%s", get_next_line(fd));
// 	// get_next_line(fd);
// 	// get_next_line(fd);

// }
