/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnauroy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:01:23 by jnauroy           #+#    #+#             */
/*   Updated: 2024/11/06 18:24:03 by jnauroy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	size_t	i;
	
	if (!s)
		return (0);
	i = 0;
	while (i < ft_strlen(s))
	{
		if (s[i] == (unsigned char)c)
			return (&s[i + 1]);
		i++;
	}
	return (0);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*ft_s;

	ft_s = (char *) s;
	i = 0;
	while (i < n)
	{
		ft_s[i] = 0;
		i++;
	}
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	limit;

	limit = -1;
	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if (nmemb >= limit / size)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, (nmemb * size));
	return (ptr);
}

char	*ft_gnljoin(char *s1, char *s2)
{
	char	*sentence;
	size_t	i;
	size_t	j;
	size_t	s1_size;
	size_t	s2_size;

	i = 0;
	j = 0;
	s1_size = ft_strlen(s1);
	s2_size = ft_strlen(s2);
	sentence = malloc((s1_size + s2_size + 1) * sizeof(char));
	if (!sentence)
		return (0);
	while (i < s1_size + s2_size)
	{
		if (i < s1_size)
			sentence[i] = s1[i];
		else if (i >= s1_size && i < s1_size + s2_size)
			sentence[i] = s2[j++];
		i++;
	}
	sentence[i] = '\0';
	free(s1);
	return (sentence);
}
