/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiribei <luiribei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 12:18:50 by luiribei          #+#    #+#             */
/*   Updated: 2024/11/04 14:51:48 by luiribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/inc/libft.h"
# include "../libft/inc/ft_printf.h"
# include "../libft/inc/get_next_line.h"
# include "../minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <limits.h>
# include <stdbool.h>

# define WALL				'1'
# define FLOOR				'0'
# define COLLECTABLE		'C'
# define PLAYER				'P'
# define MAP_EXIT			'E'

# define WALL_XPM			"assets/sprites/wall.xpm"
# define FLOOR_XPM			"assets/sprites/floor.xpm"
# define COLLECTABLE_XPM	"assets/sprites/collectable.xpm"
# define PLAYER_FRONT_XPM	"assets/sprites/player/front.xpm"
# define PLAYER_LEFT_XPM	"assets/sprites/player/left.xpm"
# define PLAYER_RIGHT_XPM	"assets/sprites/player/right.xpm"
# define PLAYER_BACK_XPM	"assets/sprites/player/back.xpm"
# define EXIT_OPEN_XPM		"assets/sprites/exit-opened.xpm"
# define EXIT_CLOSED_XPM	"assets/sprites/exit-closed.xpm"

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	char	**map_copy;
	int		map_width;
	int		map_height;
	void	*img_player;
	void	*img_floor;
	void	*img_wall;
	void	*img_collectable;
	void	*img_exit;
	int		img_width;
	int		img_height;
	int		x_player;
	int		y_player;
	int		screen_width;
	int		screen_height;
	int		n_ve;
	int		n_vc;
	int		n_c;
	int		n_e;
	int		n_p;
	int		moves;
	int		finish;
}		t_game;

void	game_init(t_game *game);
void	gameplay(t_game *game);
int		draw_game(t_game *game);
int		exit_game(t_game *game);
int		check_win(t_game *game);
char	**map_read(char *path, t_game *game);
int		check_map(t_game *game);

void	w_key(t_game *game);
void	s_key(t_game *game);
void	d_key(t_game *game);
void	a_key(t_game *game);

void	free_map(char **map);
void	print_error(char *str, t_game *game);
void	print_win(t_game *game);
void	get_win_size(t_game *game);

#endif
