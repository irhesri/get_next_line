/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhesri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 08:08:33 by irhesri           #+#    #+#             */
/*   Updated: 2021/12/18 08:10:55 by irhesri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# ifndef OPEN_MAX
#  define OPEN_MAX 1000
# endif
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

char	*ft_endlsplit(char *s1, char *s2, int *size);
char	*get_next_line(int fd);

#endif
