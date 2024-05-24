/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: envillan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 19:42:43 by envillan          #+#    #+#             */
/*   Updated: 2024/05/24 09:49:10 by envillan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stddef.h>


char	*get_next_line(int fd);
char	*ft_strdup(char *s);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strjoin(const char *s1, const char *s2);
size_t	ft_strlen(const char *s);
void	fill_str(char *res, char *s1, char *s2);

#endif
