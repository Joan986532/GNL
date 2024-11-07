/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnauroy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 13:52:34 by jnauroy           #+#    #+#             */
/*   Updated: 2024/11/07 18:17:06 by jnauroy          ###   ########.fr       */
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
			return (0);
		i++;
	}
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
	if (src[n] == '\0')
		n--;
	dest = malloc(sizeof(char) * (n + 1));
	if (!dest)
		return (0);
	i = 0;
	while (i <= n)
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
	int			size;
	char		*sentence;
	
	string = init_string(string);
	if (!string)
		return (0);
	buffer = NULL;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	size = BUFFER_SIZE;
	while (check_for_bsn(string))
	{
		size = read(fd, buffer, BUFFER_SIZE);
		if (size == -1)
			return (0);
		string = ft_gnljoin(string, buffer);
	}
	sentence = ft_create_str(string);
	free(buffer);
	return (sentence);
}
