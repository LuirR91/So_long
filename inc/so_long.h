/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiribei <luiribei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 12:18:50 by luiribei          #+#    #+#             */
/*   Updated: 2024/10/25 16:27:26 by luiribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG
# define SO_LONG

#include "../libft/inc/libft.h"
#include "../libft/inc/ft_printf.h"
#include "../libft/inc/get_next_line.h"
#include "../minilibx-linux/mlx.h"
#include <X11/X.h>
#include <X11/keysym.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

# define WIDHT 1920
# define HEIGHT 1080

# define WALL				'1'
# define FLOOR				'0'
# define COLLECTABLE		'C'
# define PLAYER				'P'
# define MAP_EXIT			'E'

# define SPEED				10

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
	void	*img_player;
	void	*img_floor;
	void	*img_wall;
	void	*img_collectable;
	void	*img_exit;
	
	int		img_width;
	int		img_height;
	
	int		x_player;
	int		y_player;
	
	int		moves;
}		t_game;

// Functions

void	game_init(t_game *game);
void	gameplay(t_game *game);
int	draw_game(t_game *game);
int	exit_game(t_game *game);

void	w_key(t_game *game);
void	s_key(t_game *game);
void	d_key(t_game *game);
void	a_key(t_game *game);

#endif
