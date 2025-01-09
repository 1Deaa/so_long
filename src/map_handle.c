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

bool	is_rectangular(t_map *map)
{
	size_t	i;

	i = 0;
	while (i < map->rows - 1)
	{
		if ((ft_strlen(map->matrix[i]) != map->cols))
			return (false);
		i++;
	}
	if (ft_strlen(map->matrix[map->rows - 1]) != map->cols - 1)
		return (false);
	return (true);
}

void	map_handle(t_map *map)
{
	size_t	i;

	i = 0;
	if (!is_rectangular(map))
	{
		ft_printf("Incorrect map format!\n");
		while (i < map->rows)
		{
			free(map->matrix[i]);
			i++;
		}
		free(map->matrix);
		exit(EXIT_FAILURE);
	}
}
