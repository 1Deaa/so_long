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
	size_t	player;
	size_t	exit;
	size_t	collectible;
	size_t	rows;
	size_t	cols;
}	t_map;

//LIBFT TOOLS
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char *str1, char *str2);
int		ft_strcmp(const char *str1, const char *str2);
char	*ft_strrchr(const char *str, int c);
char	*ft_strcpy(char *dest, const char *src);
int		open_file(const char *filename, int o_flag);

//FILE_HANDLE_UTIL.C
bool	file_exist(const char *filename);
bool	check_extension(const char *filename);
bool	is_file_empty(const char *filename);

//FILE_HANDLE.C
void	file_handle(const char *filename);

//GET_NEXT_LINE.C
char	*get_next_line(int fd);
char	*check_for_newline(char *str);

//FILL_MAP.C
size_t	count_rows(char *filename);
char	**allocate_matrix(t_map *map, char *filename);
void	fill_map(t_map *map, char *filename);
void	fail_deallocate_matrix(char **matrix, int fd);

//MAP
void	map_init(t_map *map, char *filename);
void	map_handle(t_map *map);

//MAP_HANDLE_UTIL.C
bool	check_e_p_c(t_map *map);
bool	is_valid_map(t_map *map);
void	free_map(t_map *map);
bool	is_walled(t_map *map);
bool	is_rectangular(t_map *map);

#endif