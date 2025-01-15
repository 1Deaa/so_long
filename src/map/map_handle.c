/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_handle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drahwanj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 21:02:20 by drahwanj          #+#    #+#             */
/*   Updated: 2025/01/08 21:02:21 by drahwanj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void	map_handle(t_map *map)
{
	if (!is_rectangular(map) || !is_walled(map) || !is_valid_map(map))
	{
		free_map(map);
		ft_printf("Invalid map shape!\n");
		exit(EXIT_FAILURE);
	}
	if (!check_e_p_c(map))
	{
		free_map(map);
		ft_printf("Invalid map! Exit: %d, Player: %d, Collectibles: %d\n",
			map->exit, map->player, map->collectible);
		exit(EXIT_FAILURE);
	}
	if (!is_playable(map))
	{
		free_map(map);
		ft_printf("Invalid map! Exit or Collectible is unreachable!\n");
		exit(EXIT_FAILURE);
	}
}
