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

void	map_handle(t_map *map)
{
	if (!is_rectangular(map) || !is_walled(map)
		|| !is_valid_map(map) || !check_e_p_c(map))
	{
		ft_printf("Incorrect map format!\n");
		free_map(map);
		exit(EXIT_FAILURE);
	}
}
