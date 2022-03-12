/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchetana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 10:15:26 by cchetana          #+#    #+#             */
/*   Updated: 2022/03/12 10:19:51 by cchetana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

char	*get_next_line(int fd);
char	*get_next_buff(char *buff);
char	*get_a_line(char *buff);
char	*get_a_buff(int fd, char *buff);
char	*ft_join_free(char *buff, char *tmp);
char	*ft_strjoin(char *line, char *buff);
char	*ft_strchr(const char *s, int c);
char	*ft_strcpy(char *dst, char *src);
void	*ft_calloc(size_t count, size_t size);
size_t	ft_strlen(const char *line);

#endif
