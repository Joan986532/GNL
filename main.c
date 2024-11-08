/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnauroy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:14:09 by jnauroy           #+#    #+#             */
/*   Updated: 2024/11/08 09:40:15 by jnauroy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

//V1

int	main(void)
{
	int	fd;
	char *line;

	fd = open("theclash.txt", O_RDONLY);
	do 
	{
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
	} while (line);
	close (fd);
}
