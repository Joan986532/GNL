/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnauroy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 13:52:34 by jnauroy           #+#    #+#             */
/*   Updated: 2024/11/06 18:26:41 by jnauroy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*init_string(char *string)
{
	char *temp;

	temp = NULL;
	if (string)
	{
		temp = ft_strchr(string, '\n');
		free(string);
		string = calloc(sizeof(char), 1);
		string = ft_gnljoin(string, temp);
		return (string);
	}
	string = calloc(sizeof(char), 1);
	if (!string)
		return (0);
	return (string);
}

int	check_for_bsn(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_create_str(char *src)
{
	size_t	n;
	char	*dest;
	
	n = 0;
	while (src[n] != '\0')
	{
		if (src[n++] == '\n')
			break;
	}
	dest = malloc(sizeof(char) * (n + 1));
	if (!dest)
		return (0);
	n = 0;
	while (src[n] != '\0')
	{
		dest[n] = src[n];
		if (dest[n++] == '\n')
			break;
	}
	dest[n] = '\0';
	return (dest);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char *string;
	int			size;
	char		*sentence;
	
	string = init_string(string);
	if (!string)
		return (0);
	buffer = NULL;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	size = BUFFER_SIZE;
	while (size != 0)
	{
		size = read(fd, buffer, BUFFER_SIZE);
		if (size == -1)
			return (0);
		string = ft_gnljoin(string, buffer);
		if (check_for_bsn(string))
			break ;
	}
	sentence = ft_create_str(string);
	free(buffer);
	return (sentence);
}
