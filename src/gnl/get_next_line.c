/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drahwanj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 19:40:32 by drahwanj          #+#    #+#             */
/*   Updated: 2025/01/08 19:40:33 by drahwanj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*ft_read(int fd, char *next)
{
	char	*buf;
	int		byte;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
	{
		free(next);
		return (NULL);
	}
	byte = 1;
	while (!check_for_newline(next) && byte != 0)
	{
		byte = read(fd, buf, BUFFER_SIZE);
		if (byte == -1)
		{
			free(buf);
			free(next);
			return (NULL);
		}
		buf[byte] = '\0';
		next = ft_strjoin(next, buf);
	}
	free(buf);
	return (next);
}

static char	*ft_get_line(char *next)
{
	int		i;
	char	*line;

	i = 0;
	while (next[i] && next[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
	{
		free(next);
		return (NULL);
	}
	i = 0;
	while (next[i] && next[i] != '\n')
	{
		line[i] = next[i];
		i++;
	}
	if (next[i] == '\n')
	{
		line[i] = next[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

static char	*ft_next_line(char *next)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (next[i] && next[i] != '\n')
		i++;
	if (!next[i])
	{
		free(next);
		return (NULL);
	}
	line = (char *)malloc(sizeof(char) * (ft_strlen(next) - i + 1));
	if (!line)
	{
		free(next);
		return (NULL);
	}
	i++;
	j = 0;
	while (next[i])
		line[j++] = next[i++];
	line[j] = '\0';
	free(next);
	return (line);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*next;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	next = ft_read(fd, next);
	if (!next)
		return (NULL);
	line = ft_get_line(next);
	next = ft_next_line(next);
	if (!line[0])
	{
		free(line);
		return (NULL);
	}
	return (line);
}
