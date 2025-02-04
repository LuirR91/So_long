/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiribei <luiribei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 15:15:44 by luiribei          #+#    #+#             */
/*   Updated: 2024/11/05 12:31:16 by luiribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	init_img(t_g *g)
{
	g->img_floor = mlx_xpm_file_to_image(g->mlx, \
		FLOOR_XPM, &g->img_width, &g->img_height);
	g->img_floor_update = mlx_xpm_file_to_image(g->mlx, \
		FLOOR_UPDATE_XPM, &g->img_width, &g->img_height);
	g->img_wall = mlx_xpm_file_to_image(g->mlx, \
		WALL_XPM, &g->img_width, &g->img_height);
	g->img_player = mlx_xpm_file_to_image(g->mlx, \
		PLAYER_FRONT_XPM, &g->img_width, &g->img_height);
	g->img_collectable = mlx_xpm_file_to_image(g->mlx, \
		COLLECTABLE_XPM, &g->img_width, &g->img_height);
	g->img_collectable_kill = mlx_xpm_file_to_image(g->mlx, \
		COLLECTABLE_KILL_XPM, &g->img_width, &g->img_height);
	g->img_exit = mlx_xpm_file_to_image(g->mlx, \
		EXIT_CLOSED_XPM, &g->img_width, &g->img_height);
}

void	get_win_size(t_g *g)
{
	int	y;

	g->map_width = ft_strlen(g->map[0]) * 64;
	y = 0;
	while (g->map[y])
		y++;
	g->map_height = y * 64;
	if (g->map_width > g->screen_width || \
		g->map_height > g->screen_height)
		print_error("Map is too big for the screen.", g);
}

void	g_init(t_g *g)
{
	get_win_size(g);
	g->win = mlx_new_window(g->mlx, g->map_width, \
		g->map_height, "so_long");
	g->moves = 0;
	g->finish = 0;
	init_img(g);
	draw_g(g);
}
