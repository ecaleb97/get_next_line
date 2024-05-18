/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: envillan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 20:15:04 by envillan          #+#    #+#             */
/*   Updated: 2024/05/18 20:30:19 by envillan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char *ft_calloc(size_t count, size_t size)
{
    char    *ptr;

    ptr = malloc(count * size);
    if (!ptr)
        return (NULL);
    ft_bzero(ptr, count * size);
    return (ptr);
}

static char *ft_read(int fd, char *left_string)
{
    char    *buffer;
    int     rd_bytes;

    buffer = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
    if (!buffer)
        return (NULL);
    rd_bytes = 1;
    while (rd_bytes != 0)
    {
        rd_bytes = read(fd, buffer, BUFFER_SIZE);
        if (rd_bytes == -1)
        {
            free(buffer);
            free(left_string);
            return (NULL);
        }
        buffer[rd_bytes] = '\0';
        left_string = ft_strjoin(left_string, buffer);
        if (ft_strchr(buffer, '\n'))
            break;
    }
    free(buffer);
    buffer = NULL;
    return (left_string);
}

static char     *ft_line(char *buffer)
{
    char    *line;
    int     i;

    i = 0;
    if (!buffer[i])
        return (NULL);
    while (buffer[i] && buffer != '\n')
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

static char     *ft_rest(char *save)
{
    int     i;
    int     c;
    char    *s;

    i = 0;
    while (save[i] && save[i] != '\n')
        i++;
    if (!save[i])
    {
        free(save);
        return (NULL);
    }
    s = (char *)ft_calloc(sizeof(char), (ft_strlen(save) - i));
    if (!s)
    {
        free(s);
        return (NULL);
    }
    i++;
    c = 0;
    while (save[i])
        s[c++] = save[i++];
    s[c] = '\0';
    free(save);
    return (s);
}

char    *get_next_line(int fd)
{
    static char     *buffer;
    char            *line;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    buffer = ft_read(fd, buffer);
    if (!buffer)
        return (NULL);
    line = ft_line(buffer);
    buffer = ft_rest(buffer);
    return (line);
}