/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinto-r <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 16:41:41 by rpinto-r          #+#    #+#             */
/*   Updated: 2022/03/29 04:25:56 by rpinto-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_tilemap(t_game *game)
{
	int	x;
	int	y;

	y = -1;
	while (++y < game->map.rows)
	{
		x = -1;
		while (++x < game->map.cols)
			draw_tile(game, game->map.tiles[y][x], x, y);
	}
	draw_moves_counter(game);
}

void	draw_tile(t_game *game, char c, int x, int y)
{
	draw_floor(game, x, y);
	if (c == WALL)
		draw_wall(game, x, y);
	if (c == COLLECTIBLE)
		draw_collectible(game, x, y);
	if (c == EXIT)
		draw_exit(game, x, y);
	if (c == PLAYER)
		draw_player(game, x, y);
}

void	draw_image(t_game *game, char *path, int x, int y)
{
	t_image	img;

	reset_moves_counter(game);
	img.ptr = mlx_xpm_file_to_image(game->mlx, path, &img.width, &img.height);
	mlx_put_image_to_window(game->mlx, game->window, img.ptr, \
		x * img.width, y * img.height);
	mlx_destroy_image(game->mlx, img.ptr);
}

void	draw_moves_counter(t_game *game)
{
	char	*str;

	mlx_string_put(game->mlx, game->window, \
		6, game->height + 12, WHITE, "Moves: ");
	str = ft_itoa(game->player.moves);
	mlx_string_put(game->mlx, game->window, \
		IMG_SIZE, game->height + 12, WHITE, str);
	free(str);
}

void	reset_moves_counter(t_game *game)
{
	char	*str;

	mlx_string_put(game->mlx, game->window, \
		6, game->height + 12, BLACK, "Moves: ");
	str = ft_itoa(game->player.moves - 1);
	mlx_string_put(game->mlx, game->window, \
		IMG_SIZE, game->height + 12, BLACK, str);
	free(str);
}
