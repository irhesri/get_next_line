#ifndef LIBFT_H
# define LIBFT_H

#ifdef BUFFER_SIZE
#else 
#define BUFFER_SIZE 0
#endif

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft/libft.h"
#include <fcntl.h>

char *get_next_line(int fd);
size_t	ft_strlen(const char *str);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strjoin(char *s1, char const *s2);
char	*ft_strchr(char *str);
char	*ft_strdup(char *str);

/*******************/
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int s, int fd);
#endif
