/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drahwanj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 17:50:08 by drahwanj          #+#    #+#             */
/*   Updated: 2025/01/08 17:50:09 by drahwanj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

# include <../mlx_linux/mlx.h>
# include <../ft_printf/ft_printf.h>
# include <fcntl.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <unistd.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>

//STRUCTURE
typedef struct s_map
{
	char	**matrix;
	int		rows;
	int		cols;
}	t_map;

//LIBFT
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char *str1, char *str2);
int		ft_strcmp(const char *str1, const char *str2);
char	*ft_strrchr(const char *str, int c);

//SO_LONG
bool	file_exist(const char *filename);
bool   check_extension(const char *filename);
char	*get_next_line(int fd);
char	*check_for_newline(char *str);
void		count_rows(t_map *map, char *filename);
char  **fill_map(t_map *map, char *filename);
char	**allocate_matrix(t_map *map, char *filename);

#endif