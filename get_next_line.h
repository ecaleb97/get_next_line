/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: envillan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 19:42:43 by envillan          #+#    #+#             */
/*   Updated: 2024/05/18 20:06:03 by envillan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stddef.h>

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 42

# endif

void    *ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *dest, size_t n);
char	*get_next_line(int fd);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strchr(const char *s, int i);
size_t	ft_strlen(const char *s);

#endif