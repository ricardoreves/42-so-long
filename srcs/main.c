/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinto-r <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 23:57:32 by rpinto-r          #+#    #+#             */
/*   Updated: 2022/03/29 04:25:56 by rpinto-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	update_frames(t_game *game)
{
	static int	mainframe = -1;
	static int	animeframe = -1;

	if (animeframe >= ANIMEFRAME_INTERVAL)
	{
		if (game->animeframe == 1)
			game->animeframe = -1;
		game->animeframe++;
		animeframe = 0;
	}
	animeframe++;
	if (animeframe < 0)
		draw_tilemap(game);
	else if (mainframe >= MAINFRAME_INTERVAL)
	{
		draw_tilemap(game);
		mainframe = 0;
	}
	mainframe++;
	return (0);
}

void	game_init(char **av)
{
	t_game	game;

	map_init(av[1], &game);
	game.width = IMG_SIZE * game.map.cols;
	game.height = IMG_SIZE * game.map.rows;
	game.title = av[0];
	game.animeframe = 0;
	game.mlx = mlx_init();
	game.window = mlx_new_window(game.mlx, game.width,
			game.height + 16, game.title);
	hook_init(&game);
	mlx_loop_hook(game.mlx, *update_frames, &game);
	mlx_loop(game.mlx);
}

int	main(int ac, char **av)
{
	if (ac != 2)
		game_error(ERR_MAP_REQUIRED, 0);
	game_init(av);
	return (0);
}
