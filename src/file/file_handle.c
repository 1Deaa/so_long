/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_handle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drahwanj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 19:31:48 by drahwanj          #+#    #+#             */
/*   Updated: 2025/01/08 19:31:49 by drahwanj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	file_handle(const char *filename)
{
	if (!(file_exist(filename) && check_extension(filename)
			&& !is_file_empty(filename)))
	{
		ft_printf("File is invalid!\n");
		exit(EXIT_FAILURE);
	}
}
