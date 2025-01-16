/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drahwanj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 17:50:08 by drahwanj          #+#    #+#             */
/*   Updated: 2025/01/16 14:37:11 by drahwanj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

# define BLOCK_SIZE 64

# include <mlx.h>
# include "../ft_printf/ft_printf.h"
# include <fcntl.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <unistd.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>

//STRUCTURES
# include "structure.h"

//LIBFT TOOLS
int		ft_strlen(const char *str);
char	*ft_strjoin(char *str1, char *str2);
int		ft_strcmp(const char *str1, const char *str2);
char	*ft_strrchr(const char *str, int c);
char	*ft_strcpy(char *dest, const char *src);
int		open_file(const char *filename, int o_flag);
void	*ft_memset(void *s, int c, int n);
char	*ft_strdup(const char *str);

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
int		count_rows(char *filename);
char	**allocate_matrix(t_map *map, char *filename);
void	fill_map(t_map *map, char *filename);
void	fail_deallocate_matrix(char **matrix, int fd);

//MAP
void	matrix_init(t_map *map, char *filename);
void	map_handle(t_map *map);
void	free_matrix(char **matrix, int rows);

//MAP_HANDLE_UTIL.C
bool	check_e_p_c(t_map *map);
bool	is_valid_map(t_map *map);
void	free_map(t_map *map);
bool	is_walled(t_map *map);
bool	is_rectangular(t_map *map);
bool	is_playable(t_map *map);

//FLOOD_FILL H
void	flood_fill(t_map *map, char **map_dup);
void	flood_fill_loop(t_map *flood, int x, int y);
char	**duplicate_map(char **map, int rows);

//GAME
void	window_init(t_game *game);
void	img_init(t_game *game);
void	render_map(t_game *game);
void	placetiles(t_game *game, int x, int y);

//MOVMEMENT_SYSTEM.C
int		key_hook(int keycode, t_game *game);
void	move_player(t_game *game, int x, int y);
int		check_player_move(t_game *game, int new_x, int new_y);

//CLEAN
void	clean_game(t_game *game);
void	clean_win(t_game *game);
int		close_game(t_game *game);
void	clean_img(t_game *game);

#endif
