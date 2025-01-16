/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_util.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drahwanj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 00:41:56 by drahwanj          #+#    #+#             */
/*   Updated: 2025/01/16 00:41:57 by drahwanj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill_loop(t_map *flood, int x, int y)
{
	if (flood->matrix[x][y] == '1' || flood->matrix[x][y] == 'F' ||
		flood->matrix[x][y] == 'E')
	{
		if (flood->matrix[x][y] == 'E')
		{
			flood->matrix[x][y] = '1';
			flood->exit = 0;
		}
		return ;
	}
	if (flood->matrix[x][y] == 'C')
		flood->collectible--;
	flood->matrix[x][y] = 'F';
	if (x > 0)
		flood_fill_loop(flood, x - 1, y);
	if (x < flood->rows - 1)
		flood_fill_loop(flood, x + 1, y);
	if (y > 0)
		flood_fill_loop(flood, x, y - 1);
	if (y < flood->cols - 1)
		flood_fill_loop(flood, x, y + 1);
}

char	**duplicate_map(char **map, int rows)
{
	int		i;
	char	**dup;

	dup = (char **)malloc(sizeof(char *) * (rows + 1));
	if (!dup)
		return (NULL);
	i = 0;
	while (i < rows)
	{
		dup[i] = ft_strdup(map[i]);
		i++;
	}
	dup[i] = NULL;
	return (dup);
}

void	free_matrix(char **matrix, int rows)
{
	int	i;

	i = 0;
	while (i < rows)
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}
