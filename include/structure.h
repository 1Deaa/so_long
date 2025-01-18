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
	int		player_x;
	int		player_y;
	int		exit_x;
	int		exit_y;
	int		player;
	int		exit;
	int		collectible;
	int		rows;
	int		cols;
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
	int		moves;
	int		on_screen_x;
	int		on_screen_y;
	t_map	map;
}	t_game;

#endif