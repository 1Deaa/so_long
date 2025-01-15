/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drahwanj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 08:25:09 by drahwanj          #+#    #+#             */
/*   Updated: 2025/01/13 08:25:09 by drahwanj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURE_H
# define STRUCTURE_H

typedef struct s_map
{
	char	**matrix;
	size_t	player_x;
	size_t	player_y;
	size_t	player;
	size_t	exit;
	size_t	collectible;
	size_t	rows;
	size_t	cols;
}	t_map;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	void	*img_player;
	void	*img_wall;
	void	*img_exit;
	void	*img_collect;
	void	*img_floor;
	size_t		moves;
	size_t		on_screen_x;
	size_t		on_screen_y;
	t_map	map;
}	t_game;

#endif