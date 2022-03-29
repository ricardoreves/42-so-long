/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinto-r <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 00:30:45 by rpinto-r          #+#    #+#             */
/*   Updated: 2022/03/29 04:25:56 by rpinto-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_wall(t_game *game, int x, int y)
{
	if (x == 0 && y == 0)
		draw_image(game, IMG_WALL_TL, x, y);
	else if (x == game->map.cols - 1 && y == 0)
		draw_image(game, IMG_WALL_TR, x, y);
	else if (x == 0 && y == game->map.rows - 1)
		draw_image(game, IMG_WALL_BL, x, y);
	else if (x == game->map.cols - 1 && y == game->map.rows - 1)
		draw_image(game, IMG_WALL_BR, x, y);
	else if (x == 0 || x == game->map.cols - 1)
		draw_image(game, IMG_WALL_V, x, y);
	else if (y == 0 || y == game->map.rows - 1)
		draw_image(game, IMG_WALL_H, x, y);
	else
	{
		if (x % 2 && y % 2)
			draw_image(game, IMG_WALL_2, x, y);
		else
			draw_image(game, IMG_WALL_1, x, y);
	}
}

void	draw_floor(t_game *game, int x, int y)
{
	draw_image(game, IMG_FLOOR, x, y);
}

void	draw_collectible(t_game *game, int x, int y)
{
	if (game->animeframe == 0)
		draw_image(game, IMG_COLLECTIBLE_1, x, y);
	else if (game->animeframe == 1)
		draw_image(game, IMG_COLLECTIBLE_2, x, y);
	else if (game->animeframe == 2)
		draw_image(game, IMG_COLLECTIBLE_3, x, y);
}

void	draw_player(t_game *game, int x, int y)
{	
	if (game->player.direction == KEY_UP)
		draw_image(game, IMG_PLAYER_UP, x, y);
	if (game->player.direction == KEY_DOWN)
		draw_image(game, IMG_PLAYER_DOWN, x, y);
	if (game->player.direction == KEY_LEFT)
		draw_image(game, IMG_PLAYER_LEFT, x, y);
	if (game->player.direction == KEY_RIGHT)
		draw_image(game, IMG_PLAYER_RIGHT, x, y);
}

void	draw_exit(t_game *game, int x, int y)
{
	draw_image(game, IMG_EXIT_OPEN, x, y);
	if (game->player.collects != game->map.collectibles)
		draw_image(game, IMG_EXIT_CLOSE, x, y);
}
