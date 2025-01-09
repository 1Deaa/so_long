/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drahwanj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 16:25:38 by drahwanj          #+#    #+#             */
/*   Updated: 2025/01/02 16:25:40 by drahwanj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_map		map;
	char		*filename;
	size_t		i;

	i = 0;
	filename = argv[1];
	if (argc != 2)
	{
		ft_printf("Usage: ./so_long [map.ber]\n");
		exit(EXIT_FAILURE);
	}
	file_handle(filename);
	map_init(&map, filename);
	map_handle(&map);
	while (i < map.rows)
	{
		ft_printf("%s", map.matrix[i]);
		free(map.matrix[i]);
		i++;
	}
	free(map.matrix);
}
