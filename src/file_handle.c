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

bool	check_extension(const char *filename)
{
	char	*extension;

	extension = ft_strrchr(filename, '.');
	if (!extension)
	{
		ft_printf("Error Invalid file extension!\n");
		return (false);
	}
	if (ft_strcmp(extension, ".ber"))
	{
		ft_printf("Error Invalid file extension!\n");
		return (false);
	}
	return (true);
}

bool	file_exist(const char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		perror("Could not open file!");
		return (false);
	}
	close(fd);
	return (true);
}
