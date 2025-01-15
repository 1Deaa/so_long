/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drahwanj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 14:19:51 by drahwanj          #+#    #+#             */
/*   Updated: 2025/01/09 14:19:52 by drahwanj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	assign_player_cord(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->cols)
		{
			if (map->matrix[i][j] == 'P')
			{
				map->player_x = j;
				map->player_y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	matrix_init(t_map *map, char *filename)
{
	map->player = 0;
	map->collectible = 0;
	map->exit = 0;
	map->rows = count_rows(filename);
	map->matrix = allocate_matrix(map, filename);
	fill_map(map, filename);
	map->cols = (ft_strlen(map->matrix[0]) - 1);
	map_handle(map);
	assign_player_cord(map);
}