/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drahwanj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 19:50:15 by drahwanj          #+#    #+#             */
/*   Updated: 2025/01/08 19:50:16 by drahwanj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strjoin(char *str1, char *str2)
{
	int		i;
	int		j;
	char	*new_str;

	if (!str1)
	{
		str1 = (char *)malloc(sizeof(char) * 1);
		str1[0] = '\0';
	}
	if (!str1 || !str2)
		return (NULL);
	new_str = malloc(sizeof(char) * (ft_strlen(str1) + ft_strlen(str2) + 1));
	if (!new_str)
		return (NULL);
	i = -1;
	j = 0;
	if (str1)
		while (str1[++i])
			new_str[i] = str1[i];
	while (str2[j])
		new_str[i++] = str2[j++];
	new_str[i] = '\0';
	free(str1);
	return (new_str);
}

char	*check_for_newline(char *str)
{
	if (!str)
		return (NULL);
	while (*str)
	{
		if (*str == '\n')
			return (str);
		str++;
	}
	return (NULL);
}
