#include "get_next_line.h"

char *get_next_line(int fd)
{       	
	static char	*x = NULL;
	static int	i = -1;
	char		*str;
	char		*s;
	int		len;
	

	if ((BUFFER_SIZE < 0) || (fd < 0))
		return (NULL);
	if (i != fd)
	{
		i = fd;
		s = ft_strdup(""); 
		str = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!str || !s)
			return (NULL);
		while (1)
		{
			len = read(fd, str, BUFFER_SIZE);
			if(!len)
				break;
			str[len] = '\0';
			s = ft_strjoin(s, str);
		}
		x = s;
		free(str);
	}
	str = ft_strchr(x);
	if (!str)
        str = x;
	s = ft_substr(x, 0, (ft_strlen(x) - ft_strlen(str)));
    free(x);
	x = str;
	return (s);
}

/*int main()
{
    int fd = open("text", O_RDWR);
    //int fd1 = open("text1", O_RDWR);
    int fd2 = open("text2", O_RDWR);
    char *s;
	char *s2 = "HI";
    //ft_putnbr_fd(fd1, 1);
    //ft_putstr_fd("WHAT'S UP\0\n", fd);
		do
	{
	 s = get_next_line(fd);
    printf("%s", s);
	}while (s);do
	{
	 s = get_next_line(fd2);
    printf("%s", s);
	}while (s);
    /*s = get_next_line(fd);
    ft_putstr_fd(s, 1);
    s = get_next_line(fd);
    printf("%s\n", s);
    s = get_next_line(fd);
    printf("%s", s);   s = get_next_line(fd);
    printf("%s", s);
    s = get_next_line(fd);
    ft_putstr_fd(s, 1);
    s = get_next_line(fd);
    printf("%s\n", s);
    s = get_next_line(fd);
    printf("%s", s);
}
*/