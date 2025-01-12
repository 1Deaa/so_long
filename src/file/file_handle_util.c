/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_handle_util.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drahwanj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 18:15:12 by drahwanj          #+#    #+#             */
/*   Updated: 2025/01/09 18:15:13 by drahwanj         ###   ########.fr       */
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

bool	is_file_empty(const char *filename)
{
	int		fd;
	char	buffer;
	size_t	bytes_read;

	fd = open_file(filename, O_RDONLY);
	if (fd == -1)
		return (true);
	bytes_read = read(fd, &buffer, 1);
	close(fd);
	return (bytes_read == 0);
}

bool	file_exist(const char *filename)
{
	int	fd;

	fd = open_file(filename, O_RDONLY);
	if (fd == -1)
		return (false);
	close(fd);
	return (true);
}
