/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchetana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 20:52:04 by cchetana          #+#    #+#             */
/*   Updated: 2022/03/12 10:11:49 by cchetana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *line)
{
	size_t	len;

	len = 0;
	while (line[len])
		++len;
	return (len);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;
	size_t	i;

	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < size * count)
	{
		ptr[i] = '\0';
		++i;
	}
	return ((void *)ptr);
}

char	*ft_strjoin(char *line, char *buff)
{
	char	*res;
	int		i;
	int		j;

	if (!line && !buff)
		return (NULL);
	res = (char *)malloc(ft_strlen(line) + ft_strlen(buff) + 1);
	if (res == NULL)
		return (NULL);
	i = -1;
	while (line[++i])
		res[i] = line[i];
	j = -1;
	while (buff[++j])
		res[i + j] = buff[j];
	res[i + j] = '\0';
	return (res);
}

char	*ft_strchr(const char *s, int c)
{
	int	len;
	int	i;

	len = ft_strlen((char *)s);
	i = -1;
	while (s[++i])
		if (s[i] == (unsigned char)c)
			return ((char *)&s[i]);
	if (i != len - 1 && c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

char	*ft_strcpy(char *dst, char *src)
{
	int	i;

	i = -1;
	while (src[++i])
		dst[i] = src[i];
	dst[i] = '\0';
	return (dst);
}
