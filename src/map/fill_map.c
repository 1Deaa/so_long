/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drahwanj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 21:07:41 by drahwanj          #+#    #+#             */
/*   Updated: 2025/01/08 21:07:42 by drahwanj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_rows(char *filename)
{
	int		fd;
	char	*line;
	int	i;

	i = 0;
	fd = open_file(filename, O_RDONLY);
	if (fd == -1)
	{
		exit(EXIT_FAILURE);
	}
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		i++;
	}
	close(fd);
	free(line);
	return (i);
}

void	fail_deallocate_matrix(char **matrix, int fd)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	perror("Failed to allocate memory!");
	free(matrix);
	if (fd != -1)
		close(fd);
	exit(EXIT_FAILURE);
}

char	**allocate_matrix(t_map *map, char *filename)
{
	int		fd;
	char	**matrix;
	char	*line;
	int		i;

	i = 0;
	fd = open_file(filename, O_RDONLY);
	matrix = (char **)malloc(sizeof(char *) * (map->rows));
	if (!matrix)
		fail_deallocate_matrix(matrix, fd);
	line = get_next_line(fd);
	while (line)
	{
		matrix[i++] = (char *)malloc(sizeof(char) * (ft_strlen(line) + 1));
		free(line);
		if (!matrix[i - 1])
			fail_deallocate_matrix(matrix, fd);
		line = get_next_line(fd);
	}
	close(fd);
	return (matrix);
}

void	fill_map(t_map *map, char *filename)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = open_file(filename, O_RDONLY);
	if (fd == -1)
	{
		exit(EXIT_FAILURE);
		fail_deallocate_matrix(map->matrix, fd);
	}
	line = get_next_line(fd);
	while (line)
	{
		ft_strcpy(map->matrix[i], line);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	close(fd);
}
