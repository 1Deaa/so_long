/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_handle_util.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drahwanj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 17:56:08 by drahwanj          #+#    #+#             */
/*   Updated: 2025/01/09 17:56:08 by drahwanj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	is_rectangular(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->rows)
	{
		if (((ft_strlen(map->matrix[i]) - 1) != map->cols))
			return (false);
		i++;
	}
	return (true);
}

bool	is_walled(t_map *map)
{
	int	i;

	i = 0;
	while (map->matrix[0][i] != '\n')
	{
		if (map->matrix[0][i] != '1' || map->matrix[map->rows - 1][i] != '1')
			return (false);
		i++;
	}
	i = 0;
	while (i < map->rows)
	{
		if (map->matrix[i][0] != '1' || map->matrix[i][map->cols - 1] != '1')
			return (false);
		i++;
	}
	return (true);
}

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->rows)
	{
		free(map->matrix[i]);
		i++;
	}
	free(map->matrix);
}

bool	is_valid_map(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->cols)
		{
			if (map->matrix[i][j] != '1' && map->matrix[i][j] != '0' &&
				map->matrix[i][j] != 'P' && map->matrix[i][j] != 'E' &&
					map->matrix[i][j] != 'C')
				return (false);
			if (map->matrix[i][j] == 'P')
				map->player++;
			if (map->matrix[i][j] == 'E')
				map->exit++;
			if (map->matrix[i][j] == 'C')
				map->collectible++;
			j++;
		}
		i++;
	}
	return (true);
}

bool	check_e_p_c(t_map *map)
{
	if (map->player != 1 || map->exit != 1 || map->collectible < 1)
	{
		return (false);
	}
	return (true);
}
