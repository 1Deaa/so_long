/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_system.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drahwanj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 17:55:48 by drahwanj          #+#    #+#             */
/*   Updated: 2025/01/13 17:55:48 by drahwanj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_player_move(t_game *game, int new_x, int new_y)
{
	if (game->map.matrix[new_y][new_x] == '1')
		return (1);
	if (game->map.matrix[new_y][new_x] == 'E' && game->map.collectible == 0)
	{
		ft_printf("You win!\n");
		clean_game(game);
		exit(EXIT_SUCCESS);
	}
	if (game->map.matrix[new_y][new_x] == 'C')
	{
		game->map.collectible--;
		game->map.matrix[new_y][new_x] = '0';
	}
	if (game->map.matrix[new_y][new_x] == 'E' && game->map.collectible > 0)
	{
		ft_printf("You need to collect all collectibles!\n");
		return (0);
	}
	return (0);
}

int	key_hook(int keycode, t_game *game)
{
	if (keycode == XK_Escape)
	{
		clean_game(game);
		exit(EXIT_SUCCESS);
	}
	if (keycode == XK_w || keycode == XK_W || keycode == XK_Up)
		move_player(game, 0, -1);
	else if (keycode == XK_s || keycode == XK_S || keycode == XK_Down)
		move_player(game, 0, 1);
	else if (keycode == XK_a || keycode == XK_A || keycode == XK_Left)
		move_player(game, -1, 0);
	else if (keycode == XK_d || keycode == XK_D || keycode == XK_Right)
		move_player(game, 1, 0);
	return (0);
}

void	move_player(t_game *game, int x, int y)
{
	int	new_x;
	int	new_y;

	new_x = game->map.player_x + x;
	new_y = game->map.player_y + y;
	if (check_player_move(game, new_x, new_y))
		return ;
	game->map.matrix[game->map.player_y][game->map.player_x] = '0';
	game->map.matrix[new_y][new_x] = 'P';
	if (game->map.matrix[game->map.player_y][game->map.player_x] ==
		game->map.matrix[game->map.exit_y][game->map.exit_x])
	{
		game->map.matrix[game->map.player_y][game->map.player_x] = 'E';
	}
	game->map.player_x = new_x;
	game->map.player_y = new_y;
	game->moves++;
	ft_printf("Moves: %d\n", game->moves);
	render_map(game);
}
