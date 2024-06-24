/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: envillan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 10:23:39 by envillan          #+#    #+#             */
/*   Updated: 2024/06/24 10:59:43 by envillan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	main(void)
{
	int		fd;
	int		count;
	char	*line;

	count = 0;
	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
		return (-1);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		count++;
		printf("[%d]: %s\n", count, line);
		line = NULL;
	}
	close(fd);
	return (0);
}
