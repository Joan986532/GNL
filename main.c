/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnauroy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:14:09 by jnauroy           #+#    #+#             */
/*   Updated: 2024/11/07 18:10:24 by jnauroy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

//V1

int	main(void)
{
	int	fd;
	char *line;

	line = "0";
	fd = open("theclash.txt", O_RDONLY);
	while (line != NULL) 
	{
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
	}
}
