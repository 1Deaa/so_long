/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drahwanj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 12:50:38 by drahwanj          #+#    #+#             */
/*   Updated: 2025/01/09 12:50:39 by drahwanj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	open_file(const char *filename, int o_flag)
{
	int	fd;

	fd = open(filename, o_flag);
	if (fd == -1)
	{
		perror("Could not open file!");
	}
	return (fd);
}
