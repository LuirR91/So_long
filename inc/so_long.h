/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiribei <luiribei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 12:18:50 by luiribei          #+#    #+#             */
/*   Updated: 2024/10/22 15:47:56 by luiribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG
# define SO_LONG

/* #define ESC 53			// key escape
#define ENTER 36		// key "enter"
#define FOLLOW 3		// key "f"
#define COLOR 8			// key "c"
#define UP 126			// key "arrow up"
#define DOWN 125		// key "arrow down"
#define PENGUIN 35		// key "p"
#define RAND_COLOR 15	// key "r" */

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

typedef struct s_window
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		height;
	int		width;
}		t_window;

typedef struct s_img
{
	t_window	*win;
	void		*img_ptr;
	char		*addr;
	int			h;
	int			w;
	int			bpp;
	int			endian;
	int			line_len;
}		t_img;

//	Window and Images
void		put_pixel_img(t_img *img, int x, int y, int color);
t_img		*new_image(t_window *win, int height, int width);
t_window	*new_window(int height, int width, char *str);

//	Hooks
int	exit_program (t_img	*img);
int	read_keys(int key_pressed, void *param);
int	continuous_read_keys(int key_pressed, void *param);
int	read_mouse(int	button, int mouse_x, int mouse_y, void *param);
int follow_mouse(int mouse_x, int mouse_y, void *param);

//	Square
typedef struct s_square
{
	unsigned short int	x;
	unsigned short int	y;
	unsigned short int	size;
	int					color;
}		t_square;

void	draw_square(t_square square, t_img *img);

#endif
