/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drahwanj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 01:35:33 by drahwanj          #+#    #+#             */
/*   Updated: 2025/01/16 01:35:34 by drahwanj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strdup(const char *str)
{
	char	*dup;
	int		size;

	size = ft_strlen(str) + 1;
	dup = (char *)malloc(size);
	if (!dup)
		return (NULL);
	ft_strcpy(dup, str);
	return (dup);
}
