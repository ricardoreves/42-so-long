/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinto-r <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 00:24:02 by rpinto-r          #+#    #+#             */
/*   Updated: 2022/03/29 04:46:48 by rpinto-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define WHITE 0x00FFFFFF
# define BLACK 0x00000000
# define MAINFRAME_INTERVAL 1000
# define ANIMEFRAME_INTERVAL 5000
# define BUFFER_SIZE 4242

# ifdef __APPLE__
#  define KEY_UP 13
#  define KEY_LEFT 0
#  define KEY_DOWN 1
#  define KEY_RIGHT 2
#  define KEY_RESET 15
#  define KEY_EXIT 53
# elif defined __unix__
#  define KEY_UP 119
#  define KEY_LEFT 97
#  define KEY_DOWN 115
#  define KEY_RIGHT 100
#  define KEY_RESET 114
#  define KEY_EXIT 65307
# endif

# define IMG_SIZE 48
# define IMG_PLAYER_UP "./imgs/sprites/player-up.xpm"
# define IMG_PLAYER_LEFT "./imgs/sprites/player-left.xpm"
# define IMG_PLAYER_DOWN "./imgs/sprites/player-down.xpm"
# define IMG_PLAYER_RIGHT "./imgs/sprites/player-right.xpm"
# define IMG_WALL_TL "./imgs/sprites/wall_tl.xpm"
# define IMG_WALL_TR "./imgs/sprites/wall_tr.xpm"
# define IMG_WALL_BL "./imgs/sprites/wall_bl.xpm"
# define IMG_WALL_BR "./imgs/sprites/wall_br.xpm"
# define IMG_WALL_H "./imgs/sprites/wall_h.xpm"
# define IMG_WALL_V "./imgs/sprites/wall_v.xpm"
# define IMG_WALL_1 "./imgs/sprites/wall_1.xpm"
# define IMG_WALL_2 "./imgs/sprites/wall_2.xpm"
# define IMG_WALL_3 "./imgs/sprites/wall_3.xpm"
# define IMG_FLOOR "./imgs/sprites/floor.xpm"
# define IMG_COLLECTIBLE_1 "./imgs/sprites/collectible_1.xpm"
# define IMG_COLLECTIBLE_2 "./imgs/sprites/collectible_2.xpm"
# define IMG_COLLECTIBLE_3 "./imgs/sprites/collectible_3.xpm"
# define IMG_EXIT_OPEN "./imgs/sprites/exit_open.xpm"
# define IMG_EXIT_CLOSE "./imgs/sprites/exit_close.xpm"

# define MAP_CHARSET "01CEP"
# define MAP_FILETYPE ".ber"
# define ERR_MAP_REQUIRED "Require a map file"
# define ERR_MAP_NOT_FOUND "No such map file"
# define ERR_MAP_OPEN_FAIL "Unable to open map file"
# define ERR_MAP_INVALID_FILETYPE "The map file is not a [.ber]"
# define ERR_MAP_INVALID_CHARSET "The map contains forbidden characters"
# define ERR_MAP_INVALID_COLS "The map contains columns with different sizes"
# define ERR_MAP_INVALID_WALL "The map contains breaches in the wall"
# define ERR_MAP_INVALID "The map is not valid"
# define ERR_MAP_INVALID_COLLECTIBLE "The map does not contain an collectible"
# define ERR_MAP_INVALID_EXIT "The map does not contain an exit"
# define ERR_MAP_INVALID_PLAYER "The map must contain one player"
# define ERR_MALLOC_FAIL "The malloc failed"
# define MSG_GAME_END "Congratulations, you ate all the watermelons :D"

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

# include "mlx.h"
# include "libft.h"

enum e_charset
{
	WALL = '1',
	FLOOR = '0',
	EXIT = 'E',
	PLAYER = 'P',
	COLLECTIBLE = 'C'
};

typedef struct s_image
{
	void	*ptr;
	char	*path;
	int		width;
	int		height;
}			t_image;

typedef struct s_position {
	int	x;
	int	y;
}		t_position;

typedef struct s_map
{
	char	**tiles;
	char	**snapshot;
	char	*path;
	int		cols;
	int		rows;
	int		players;
	int		collectibles;
	int		exits;
}			t_map;

typedef struct s_player
{
	int		x;
	int		y;
	int		x_origin;
	int		y_origin;
	int		direction;
	int		moves;
	int		collects;
	char	previous;
}			t_player;

typedef struct s_game
{
	char		*title;
	void		*mlx;
	void		*window;
	int			width;
	int			height;
	int			animeframe;
	t_map		map;
	t_player	player;
}				t_game;

char	*get_next_line(int fd);
char	*ft_return_next_line(char **buffer);
int		ft_has_next_line(char *s);
int		ft_length_next_line(char *s);
char	*ft_free(char *str);
char	*ft_concat_buffer(char *buffer, char *buffer_read);
void	ft_update_buffer(char **buffer, int start);

void	map_init(char *path, t_game *game);
void	map_rows(t_game *game);
void	map_build(t_game *game);
void	map_free(t_game *game);
void	map_snapshot(t_game *game);
void	map_verify_wall(t_game *game);
void	map_verify_charset(t_game *game);
void	map_verify_components(t_game *game);

void	draw_tilemap(t_game *game);
void	draw_tile(t_game *game, char c, int x, int y);
void	draw_image(t_game *game, char *path, int x, int y);
void	draw_wall(t_game *game, int x, int y);
void	draw_floor(t_game *game, int x, int y);
void	draw_collectible(t_game *game, int x, int y);
void	draw_player(t_game *game, int x, int y);
void	draw_exit(t_game *game, int x, int y);
void	draw_moves_counter(t_game *game);
void	reset_moves_counter(t_game *game);

void	game_init(char **av);
void	game_error(char *message, t_game *game);
void	game_end(t_game *game);
void	game_exit(t_game *game);
void	game_reset(t_game *game);

void	hook_init(t_game *game);
int		hook_key_press(int keycode, t_game *game);
int		hook_close_window(int keycode, t_game *game);

void	player_init(t_game *game, int x, int y);
void	player_move_up(t_game *game);
void	player_move_down(t_game *game);
void	player_move_left(t_game *game);
void	player_move_right(t_game *game);

int		isfiletype(char *path, char *type);
#endif