/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnauroy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 13:52:34 by jnauroy           #+#    #+#             */
/*   Updated: 2024/11/08 17:44:48 by jnauroy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*init_string(char *string)
{
	char 	*temp;

	if (string)
	{
		temp = ft_strchr(string, '\n');
		free(string);
		if (!temp || !i)
			return (0);
		string = ft_calloc(sizeof(char), 1);
		if (!string)
			return (0);
		string = ft_gnljoin(string, temp);
		return (string);
	}
	string = ft_calloc(sizeof(char), 1);
	if (!string)
		return (0);
	return (string);
}

int	check_for_bsn(char *str, int size)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(str))
	{
		if (str[i] == '\n')
			return (0);
		i++;
	}
	if (size == -1)
		return (1);
	if (size < BUFFER_SIZE && str[i] == '\0')
		return (0);
	return (1);
}

char	*ft_create_str(char *src)
{
	size_t	n;
	char	*dest;
	size_t	i;

	n = 0;
	while (src[n] != '\0' && src[n] != '\n')
		n++;
	if (src[n] == '\n')
		n++;
	dest = malloc(sizeof(char) * n);
	if (!dest)
		return (0);
	i = 0;
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char *string;
	char		*sentence;
	int			size;
	
	string = init_string(string);
	if (!string)
		return (0);
	size = -1;
	while (check_for_bsn(string, size))
	{
		buffer = NULL;
		buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buffer)
			return (0);
		size = read(fd, buffer, BUFFER_SIZE);
		if (size == -1)
			return (0);
		string = ft_gnljoin(string, buffer);
		free(buffer);
	}
	sentence = ft_create_str(string);
	return (sentence);
}
