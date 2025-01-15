/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drahwanj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 16:25:38 by drahwanj          #+#    #+#             */
/*   Updated: 2025/01/02 16:25:40 by drahwanj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_game	game;
	char		*filename;

	filename = argv[1];
	if (argc != 2)
	{
		ft_printf("Usage: ./so_long [map.ber]\n");
		exit(EXIT_FAILURE);
	}
	file_handle(filename);
	ft_memset(&game, 0, sizeof(t_game));
	ft_memset(&(game.map), 0, sizeof(t_map));
	matrix_init(&(game.map), filename);
	window_init(&game);
	img_init(&game);
	render_map(&game);
	mlx_hook(game.win, DestroyNotify, StructureNotifyMask, close_game, &game);
	mlx_hook(game.win, KeyPress, KeyPressMask, key_hook, &game);
	mlx_loop_hook(game.mlx, game_loop, &game);
	mlx_loop(game.mlx);
	clean_game(&game);
	return (0);
}
