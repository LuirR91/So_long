/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiribei <luiribei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 12:18:50 by luiribei          #+#    #+#             */
/*   Updated: 2024/10/24 13:40:34 by luiribei         ###   ########.fr       */
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

# define WALL				'1'
# define FLOOR				'0'
# define COLLECTABLE		'C'
# define PLAYER				'P'
# define MAP_EXIT			'E'

# define SPEED				10

# define W					119
# define A					97
# define S					115
# define D					100

# define UP					65362
# define LEFT				65361
# define RIGHT				65363
# define DOWN				65364

# define ESC				65307
# define Q					113

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
	int		map_w;
	int		map_h;
	int		img_player;
	int		img_w;
	int		img_h;
	int		x_player;
	int		y_player;
	int		moves;
	int		endgame;
}		t_game;

/* typedef struct s_image
{
	t_game	*game;
	void	*img_ptr;
	char	*addr;
	int		h;
	int		w;
	int		bpp;
	int		endian;
	int		line_len;
}		t_image; */

// Functions
int	exit_game(t_game *game);
void	game_init(t_game *game);
void	gameplay(t_game *game);

#endif
