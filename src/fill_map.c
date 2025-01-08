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

void	count_rows(t_map *map, char *filename)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		perror("Could not open file!");
		exit(EXIT_FAILURE);
	}
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		map->rows++;
	}
	close(fd);
	free(line);
}

char	**allocate_matrix(t_map *map, char *filename)
{
	int		fd;
	char	**matrix;
	char	*line;
	int		i;

	i = 0;
	count_rows(map, filename);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		perror("Could not open file!");
		exit(EXIT_FAILURE);
	}
	matrix = (char **)malloc(sizeof(char *) * (map->rows));
	ft_printf("Rows: %d\n", map->rows);
	if (!matrix)
	{
		perror("Could not allocate memory!");
		exit(EXIT_FAILURE);
	}
	line = get_next_line(fd);
	while (line)
	{
		matrix[i] = malloc(sizeof(char) * (ft_strlen(line) + 1));
		free(line);
		line = get_next_line(fd);
		i++;
	}
	close(fd);
	return (matrix);
}
/*
char	**fill_map(t_map *map, char *filename)
{
}
*/