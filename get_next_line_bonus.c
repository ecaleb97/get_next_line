/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: envillan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 18:47:53 by envillan          #+#    #+#             */
/*   Updated: 2024/06/20 19:19:34 by envillan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;

	ptr = (void *)malloc(count + size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, count + size);
	return (ptr);
}

static char	*ft_read(int fd, char *str)
{
	char	*buffer;
	int		read_bytes;

	buffer = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!buffer)
		return (NULL);
	read_bytes = 1;
	while (read_bytes != 0)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buffer);
			free(str);
			return (NULL);
		}
		buffer[read_bytes] = '\0';
		str = ft_strjoin(str, buffer);
		if (ft_strchr(str, '\n'))
			break ;
	}
	free(buffer);
	buffer = NULL;
	return (str);
}

static char	*ft_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] != '\n' && buffer[i] == '\0')
		line = ft_calloc(i + 1, sizeof(char));
	else
		line = ft_calloc(i + 2, sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] && buffer[i] == '\n')
		line[i++] = '\n';
	return (line);
}

static char	*ft_rest(char *save)
{
	int		i;
	int		c;
	char	*str;

	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free(save);
		return (NULL);
	}
	str = (char *)ft_calloc(sizeof(char), (ft_strlen(save) - i));
	if (!str)
	{
		free(str);
		return (NULL);
	}
	i++;
	c = 0;
	while (save[i])
		str[c++] = save[i++];
	str[c] = '\0';
	free(save);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*buffer[1045];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer[fd] = ft_read(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	line = ft_line(buffer[fd]);
	buffer[fd] = ft_rest(buffer[fd]);
	return (line);
}
