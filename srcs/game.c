/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinto-r <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 16:40:03 by rpinto-r          #+#    #+#             */
/*   Updated: 2022/03/29 04:44:04 by rpinto-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_exit(t_game *game)
{
	if (game)
	{
		if (!game->window)
			mlx_destroy_window(game->mlx, game->window);
		map_free(game);	
	}
	exit(0);
}

void	game_error(char *message, t_game *game)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(message, 2);
	game_exit(game);
}

void	game_end(t_game *game)
{
	if (game->player.collects == game->map.collectibles)
	{
		ft_putendl_fd(MSG_GAME_END, 1);
		game_exit(game);
	}
}

void	game_reset(t_game *game)
{
	int	x;
	int	y;

	reset_moves_counter(game);
	game->player.moves = 0;
	game->player.collects = 0;
	game->player.x = game->player.x_origin;
	game->player.y = game->player.y_origin;
	y = -1;
	while (++y < game->map.rows)
	{
		x = -1;
		while (++x < game->map.cols)
			game->map.tiles[y][x] = game->map.snapshot[y][x];
	}
}
