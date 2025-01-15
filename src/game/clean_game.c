/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drahwanj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 18:50:51 by drahwanj          #+#    #+#             */
/*   Updated: 2025/01/13 18:50:51 by drahwanj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	clean_img(t_game *game)
{
	if (game->img_wall)
	{
		mlx_destroy_image(game->mlx, game->img_wall);
		game->img_wall = NULL;
	}
	if (game->img_floor)
	{
		mlx_destroy_image(game->mlx, game->img_floor);
		game->img_floor = NULL;
	}
	if (game->img_player)
	{
		mlx_destroy_image(game->mlx, game->img_player);
		game->img_player = NULL;
	}
	if (game->img_exit)
	{
		mlx_destroy_image(game->mlx, game->img_exit);
		game->img_exit = NULL;
	}
	if (game->img_collect)
	{
		mlx_destroy_image(game->mlx, game->img_collect);
		game->img_collect = NULL;
	}
}

void	clean_win(t_game *game)
{
	if (game->win)
	{
		mlx_destroy_window(game->mlx, game->win);
		game->win = NULL;
	}
	if (game->mlx)
		mlx_destroy_display(game->mlx);
	if (game->mlx)
	{
		free(game->mlx);
		game->mlx = NULL;
	}
	if (game->map.matrix)
	{
		free_map(&(game->map));
		game->map.matrix = NULL;
	}
}

void	clean_game(t_game *game)
{
	clean_img(game);
	clean_win(game);
}
