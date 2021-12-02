#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

static char	*my_assignment(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	str = (char *) malloc(sizeof(char) * (len + 1));
	if (str)
	{
		if (start < ft_strlen(s))
		{
			i = 0;
			while (i < len && s[start])
			{
				str[i] = s[start];
				i++;
				start++;
			}
			str[i] = '\0';
		}
		else
			*str = '\0';
		return (str);
	}
	return (NULL);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*str;

	if (s && len > 0)
	{
		if (ft_strlen(s) < start)
			len = 0;
		else if (len > ft_strlen(s) - start)
			len = ft_strlen(s) - start + 1;
		str = my_assignment(s, start, len);
		return (str);
	}
	return (NULL);
}

static char	*my_strcat(char *str, char const *s1, char const *s2)
{
	int	i;

	i = 0;
	while (*s1)
	{
		str[i] = *s1;
		i++;
		s1++;
	}
	while (*s2)
	{
		str[i] = *s2;
		i++;
		s2++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*str;
	int		size;

	if (s1 && s2)
	{
		if (!*s1 && !*s2)
		{
			str = (char *) malloc(1);
			*str = '\0';
			return (str);
		}
		size = ft_strlen(s1) + ft_strlen(s2) + 1;
		size *= sizeof(char);
		str = (char *) malloc(size);
		if (str)
		{
			str = my_strcat(str, s1, s2);
			free(s1);
			return (str);
		}
	}
	if (s1)
		free(s1);
	return (NULL);
}

char	*ft_strchr(char *str)
{
	char	*ptr;
	size_t	i;

	i = 0;
	if (!str)
		return(NULL);	
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i])
		i++;
	ptr = ft_substr(str, i, (ft_strlen(str) - i)); 
	return (ptr);
}
