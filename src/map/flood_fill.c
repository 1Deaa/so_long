/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drahwanj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 22:41:47 by drahwanj          #+#    #+#             */
/*   Updated: 2025/01/15 22:41:47 by drahwanj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(t_map *map, char **map_dup)
{
	t_map	flood;

	flood = *map;
	flood.matrix = map_dup;
	flood_fill_loop(&flood, flood.player_y, flood.player_x);
	map->collectible = flood.collectible;
	map->exit = flood.exit;
}
