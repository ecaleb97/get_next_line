/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: envillan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 18:37:20 by envillan          #+#    #+#             */
/*   Updated: 2024/06/20 19:13:19 by envillan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	ft_bzero(void *dest, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)dest)[i] = 0;
		i++;
	}
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*aux;
	size_t	i;
	size_t	j;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s2)
		return (NULL);
	aux = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!aux)
		return (NULL);
	i = 0;
	if (s1)
		while (s1[j] != '\0')
			aux[i++] = s1[j++];
	j = 0;
	while (s2[j] != '\0')
		aux[i++] = s2[j++];
	aux[i] = '\0';
	free(s1);
	return (aux);
}

char	*ft_strchr(char *str, int c)
{
	while (*str != '\0' && (char)c != *str)
		str++;
	if (*str == (char)c)
		return ((char *)c);
	else
		return (0);
}
