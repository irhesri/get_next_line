/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhesri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 08:11:03 by irhesri           #+#    #+#             */
/*   Updated: 2021/12/18 08:11:32 by irhesri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

char	*ft_endlsplit(char *s1, char *s2, int *size);
char	*get_next_line(int fd);

#endif
