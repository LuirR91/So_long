/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiribei <luiribei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 12:18:50 by luiribei          #+#    #+#             */
/*   Updated: 2024/10/23 16:55:18 by luiribei         ###   ########.fr       */
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

# define W					119
# define A					97
# define S					115
# define D					100

# define UP					65362
# define LEFT				65361
# define RIGHT				65363
# define DOWN				65364

# define ESC				65307

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
	int		height;
	int		width;
}		t_game;

typedef struct s_image
{
	t_game	game;
	void	*img_ptr;
	char	*addr;
	int		h;
	int		w;
	int		bpp;
	int		endian;
	int		line_len;
}		t_image;

//	Window and Images
void		my_mlx_pixel_put(t_image *img, int x, int y, int color);
t_image		*new_image(t_game *win, int height, int width);
t_game	*new_window(int height, int width, char *str);

//	Hooks
int	exit_program (t_image	*img);

#endif
