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

void	map_init(t_map *map, char *filename)
{
	map->rows = count_rows(filename);
	map->matrix = allocate_matrix(map, filename);
	fill_map(map, filename);
	map->cols = ft_strlen(map->matrix[0]);
}
