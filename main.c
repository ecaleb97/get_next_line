/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: envillan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 10:23:39 by envillan          #+#    #+#             */
/*   Updated: 2024/05/24 10:43:22 by envillan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int main(void)
{
	int		fd;
	int		count;
	char	*next_line;

	count = 0;
	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("Error opening file");
		return (1);
	}

	while (1)
	{
		next_line = get_next_line(fd);
		if (next_line == NULL)
			break ;
		count++;
		printf("[%d]: %s\n", count, next_line);
		next_line = NULL;
	}
	close(fd);
	return (0);
}
