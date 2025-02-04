/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiribei <luiribei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 15:15:54 by luiribei          #+#    #+#             */
/*   Updated: 2024/11/05 13:55:01 by luiribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	put_img(t_g *g, void *img, int x, int y)
{
	mlx_put_image_to_window(g->mlx, g->win, img, x * 64, y * 64);
}

static void	put_player(t_g *g, void *img, int x, int y)
{
	g->xp = x;
	g->yp = y;
	put_img(g, img, x, y);
}

static void	put_exit(t_g *g, int x, int y)
{
	if (g->n_c == 0)
	{
		mlx_destroy_image(g->mlx, g->img_exit);
		g->img_exit = mlx_xpm_file_to_image(g->mlx, \
			EXIT_OPEN_XPM, &g->img_width, &g->img_height);
	}
	put_img(g, g->img_exit, x, y);
}

static void	draw_extra_g(t_g *g)
{
	int	y;
	int	x;

	y = 0;
	while (g->map[y])
	{
		x = 0;
		while (g->map[y][x])
		{
			if (g->map[y][x] == '1')
				put_img(g, g->img_wall, x, y);
			else if (g->map[y][x] == '0')
				put_img(g, g->img_floor, x, y);
			else if (g->map[y][x] == 'C')
				put_img(g, g->img_collectable, x, y);
			else if (g->map[y][x] == 'K')
				put_img(g, g->img_collectable_kill, x, y);
			else if (g->map[y][x] == 'F')
				put_img(g, g->img_floor_update, x, y);
			x++;
		}
		y++;
	}
}

int	draw_g(t_g *g)
{
	int	y;
	int	x;

	y = 0;
	while (g->map[y])
	{
		x = 0;
		while (g->map[y][x])
		{
			if (g->map[y][x] == 'P')
				put_player(g, g->img_player, x, y);
			else if (g->map[y][x] == 'E')
				put_exit(g, x, y);
			x++;
		}
		y++;
	}
	draw_extra_g(g);
	return (0);
}
