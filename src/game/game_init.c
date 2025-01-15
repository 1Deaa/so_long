/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drahwanj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:15:07 by drahwanj          #+#    #+#             */
/*   Updated: 2025/01/13 15:15:07 by drahwanj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	img_init(t_game *game)
{
	int		img_width;
	int		img_height;

	game->img_wall = mlx_xpm_file_to_image(game->mlx, "xpm/wall.xpm",
			&img_width, &img_height);
	game->img_floor = mlx_xpm_file_to_image(game->mlx, "xpm/floor.xpm",
			&img_width, &img_height);
	game->img_player = mlx_xpm_file_to_image(game->mlx, "xpm/player.xpm",
			&img_width, &img_height);
	game->img_exit = mlx_xpm_file_to_image(game->mlx, "xpm/exit.xpm",
			&img_width, &img_height);
	game->img_collect = mlx_xpm_file_to_image(game->mlx, "xpm/collect.xpm",
			&img_width, &img_height);
	if (!game->img_wall || !game->img_floor || !game->img_player
		|| !game->img_exit || !game->img_collect)
	{
		ft_printf("Error loading images!\n");
		exit(EXIT_FAILURE);
	}
}

void	window_init(t_game *game)
{
	int		win_width;
	int		win_height;

	game->mlx = mlx_init();
	if (!game->mlx)
	{
		ft_printf("Error initializing mlx!\n");
		exit(EXIT_FAILURE);
	}
	game->moves = 0;
	win_width = game->map.cols * BLOCK_SIZE;
	win_height = game->map.rows * BLOCK_SIZE;
	game->win = mlx_new_window(game->mlx, win_width, win_height, "so_long");
	if (!game->win)
	{
		ft_printf("Error creating window!\n");
		exit(EXIT_FAILURE);
	}
}

void	placetiles(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, game->img_floor,
		game->on_screen_x, game->on_screen_y);
	if (game->map.matrix[y][x] == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->img_wall,
			game->on_screen_x, game->on_screen_y);
	if (game->map.matrix[y][x] == 'P')
		mlx_put_image_to_window(game->mlx, game->win, game->img_player,
			game->on_screen_x, game->on_screen_y);
	if (game->map.matrix[y][x] == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->img_exit,
			game->on_screen_x, game->on_screen_y);
	if (game->map.matrix[y][x] == 'C')
		mlx_put_image_to_window(game->mlx, game->win, game->img_collect,
			game->on_screen_x, game->on_screen_y);
}

void	render_map(t_game *game)
{
	int		x_pos;
	int		y_pos;

	y_pos = 0;
	while (y_pos < game->map.rows)
	{
		x_pos = 0;
		while (x_pos < game->map.cols)
		{
			game->on_screen_x = x_pos * BLOCK_SIZE;
			game->on_screen_y = y_pos * BLOCK_SIZE;
			placetiles(game, x_pos, y_pos);
			x_pos++;
		}
		y_pos++;
	}
}
