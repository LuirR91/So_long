/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiribei <luiribei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 18:50:24 by luiribei          #+#    #+#             */
/*   Updated: 2024/10/15 12:52:47 by luiribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx/mlx.h"
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 900
#define HEIGHT 600
#define ESC 53
#define W	13
#define A	0
#define S	1
#define D	2

typedef struct	s_data
{
	void	*mlx;
	void	*mlx_win;
	int		box_x;
	int		box_y;
}		t_data;

typedef struct s_obj
{
	void	*img;
	int		w;
	int		h;
	int		x;
	int		y;
	struct s_obj	*next;	
}		t_obj;

int	keys(int keycode, t_data *data)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(data->mlx, data->mlx_win);
		free(data);
		exit(1);
	}
	else if (keycode == W)
		data->box_y -= 10;
	else if (keycode == A)
		data->box_x -= 10;
	else if (keycode == S)
		data->box_y += 10;
	else if (keycode == D)
		data->box_x += 10;
	return (0);
}

int	render_square(t_data *data)
{
	int	x = 350;
	int	y = 350;
	mlx_clear_window(data->mlx, data->mlx_win);
	while (x < 450)
	{
		while (y < 450)
		{
			mlx_pixel_put(data->mlx, data->mlx_win, x + data->box_x, y + data->box_y, 0x66FFFF);
			y++;
		}
		y = 350;
		x++;
	}
	mlx_do_sync(data->mlx);
	return (1);
}

int	main (void)
{
	t_data	*data;

	data = NULL;
	data = malloc(sizeof(t_data));

	data->box_x = 0;
	data->box_y = 0;
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "hi");

	mlx_loop_hook(data->mlx, render_square, data);
	mlx_hook(data->mlx_win, 2, 0, keys, data);
	mlx_loop(data->mlx);
}

// cc main.c libmlx.a -framework AppKit -framework OpenGL