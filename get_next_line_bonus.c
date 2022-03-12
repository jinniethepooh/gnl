/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchetana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 10:14:59 by cchetana          #+#    #+#             */
/*   Updated: 2022/03/12 10:20:03 by cchetana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_join_free(char *buff, char *tmp)
{
	char	*full_buff;

	if (!tmp)
		return (buff);
	full_buff = ft_strjoin(buff, tmp);
	free(buff);
	return (full_buff);
}

char	*get_a_buff(int fd, char *buff)
{
	int		fd_read;
	char	*tmp;

	if (!buff)
		buff = ft_calloc(1, 1);
	tmp = ft_calloc(BUFFER_SIZE + 1, 1);
	fd_read = read(fd, tmp, BUFFER_SIZE);
	while (fd_read > 0)
	{
		tmp[fd_read] = '\0';
		buff = ft_join_free(buff, tmp);
		if (ft_strchr(tmp, '\n'))
		{
			free(tmp);
			return (buff);
		}
		fd_read = read(fd, tmp, BUFFER_SIZE);
	}
	free(tmp);
	return (buff);
}

char	*get_a_line(char *buff)
{
	size_t	len;
	size_t	i;
	char	*line;

	len = 0;
	while (!buff[len])
		return (NULL);
	while (buff[len] && buff[len] != '\n')
		++len;
	if (buff[len] == '\n')
		len += 1;
	line = ft_calloc(len + 1, sizeof(char));
	if (!line)
		return (NULL);
	i = -1;
	while (++i < len)
		line[i] = buff[i];
	return (line);
}

char	*get_next_buff(char *buff)
{
	char	*next;
	int		i;

	i = 0;
	while (buff[i] && buff[i] != '\n')
		++i;
	if (!buff[i])
	{
		free(buff);
		return (NULL);
	}
	if (buff[i] == '\n')
		++i;
	next = (char *)malloc(ft_strlen(&buff[i]) + 1);
	if (!next)
	{
		free(buff);
		return (NULL);
	}
	ft_strcpy(next, &buff[i]);
	free(buff);
	return (next);
}

char	*get_next_line(int fd)
{
	static char	*buff[OPEN_MAX];
	char		*line;

	if (BUFFER_SIZE < 1 || fd < 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buff[fd] = get_a_buff(fd, buff[fd]);
	line = get_a_line(buff[fd]);
	buff[fd] = get_next_buff(buff[fd]);
	return (line);
}
